#include "fresalgc.h"

FreSalGC::~FreSalGC(){
    if(graph)
    {
        delete graph;
    }
}

float FreSalGC::NWeight(Vec3i c1, Vec3i c2)
{
    double delta = 1.0;
    double dist = (c1.val[0] - c2.val[0]) * (c1.val[0] - c2.val[0]) +
            (c1.val[1] - c2.val[1]) * (c1.val[1] - c2.val[1]) +
            (c1.val[2] - c2.val[2]) * (c1.val[2] - c2.val[2]);
    const double EPSILON = 0.01;

    float w = exp(-dist/delta)/(EPSILON + dist);

    return w;
}

void FreSalGC::conGraph()
{
    int indexPt = 0;
    float EPSILON = 0.0000001;
    for(int h=0; h < imgSal.rows; h++)
    {
        for(int w=0; w < imgSal.cols; w++)
        {
            float e0 = imgSal.at<float>(h, w);
            float e1 = 1 - e0;

            //cout << e0 << " " << e1 << endl;
            e0 += EPSILON;
            e1 += EPSILON;
            graph->add_node();
            graph->add_tweights(indexPt, e0, e1);

            if(w > 0)
            {
                Vec3i c1 = imgLab.at<Vec3b>(h, w-1);
                Vec3i c2 = imgLab.at<Vec3b>(h, w);
                float e2 = NWeight(c1,c2);
                graph->add_edge(indexPt, indexPt-1, e2, e2);
            }
            if(h > 0)
            {
                Vec3i c1 = imgLab.at<Vec3b>(h-1, w);
                Vec3i c2 = imgLab.at<Vec3b>(h, w);
                float e2 = NWeight(c1, c2);
                graph->add_edge(indexPt, indexPt-imgSal.cols, e2, e2);
            }
            indexPt++;
        }
    }
}

int FreSalGC::runMaxflow()
{
    // 通过Frequency-tuned 方法 得到显著性图
    calSal();

    // 构建图
    conGraph();

    // 最大流算法
    return graph->maxflow();
}

void FreSalGC::segGraphCut()
{
    int energy = runMaxflow();
    cout << "Energy: " << energy << endl;

    int height = imgLab.rows;
    int width = imgLab.cols;


    imgSeg = Mat::zeros(height, width, CV_8UC1);

    int indexPt = 0;
    for(int h=0; h < height; h++)
    {
        unsigned char *p = (unsigned char *)imgSeg.data + h*width;
        for(int w=0; w < width; w++)
        {
            if(graph->what_segment(indexPt) == GraphType::SOURCE)
            {
                *p = 255;
            }
            p++;
            indexPt++;
        }
    }
}
