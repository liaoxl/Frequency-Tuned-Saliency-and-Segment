#ifndef FRESALIENCY_H
#define FRESALIENCY_H

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

class FreSaliency
{
public:
    FreSaliency(Mat inImg) : imgRGB(inImg){
        cvtColor(imgRGB, imgLab, CV_RGB2Lab);
    }
    ~FreSaliency();

public:
    void calSal();
    void segMs();

public:
    Mat imgRGB;
    Mat imgLab;
    Mat imgSal;
    Mat imgMs;
    Mat gaussImg;
};

#endif // FRESALIENCY_H
