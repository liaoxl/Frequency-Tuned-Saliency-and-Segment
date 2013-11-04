#ifndef PIXELHIST_H
#define PIXELHIST_H

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <string.h>

#define MAX_VAL 255

using namespace cv;

class PixelHist
{
public:
    PixelHist()
    {
        memset(ph, 0, sizeof(ph));
    }

    void GetHist();
    void addImg(Mat img);

public:
    int ph[MAX_VAL][MAX_VAL][MAX_VAL];

};

#endif // PIXELHIST_H
