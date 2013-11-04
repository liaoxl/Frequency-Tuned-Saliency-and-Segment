#ifndef FRESALGC_H
#define FRESALGC_H

#include "fresaliency.h"
#include "maxflow-v3.01/graph.h"
#include <cmath>

typedef Graph<float,float,float> GraphType;

class FreSalGC : public FreSaliency
{
public:
    FreSalGC(Mat inImg) : FreSaliency(inImg){
        graph = new GraphType(inImg.cols*inImg.rows, inImg.cols*inImg.rows*2);
    }
    ~FreSalGC();

    void segGraphCut();

private:
    float NWeight(Vec3i c1, Vec3i c2);
    void conGraph();
    int runMaxflow();


private:
    GraphType *graph;

public:
    Mat imgSeg;
};

#endif // FRESALGC_H
