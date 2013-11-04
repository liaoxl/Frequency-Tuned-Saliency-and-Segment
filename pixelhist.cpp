#include "pixelhist.h"

void PixelHist::GetHist()
{
}

void PixelHist::addImg(Mat img)
{
    int height = img.rows;
    int width = img.cols;

    Vec3i v;

    for(int i=0; i < height; i++)
    {
        for(int j=0; j < width; j++)
        {
            v = img.at<Vec3b>(i,j);
            ph[v.val[0]][v.val[1]][v.val[2]] += 1;
        }
    }
}
