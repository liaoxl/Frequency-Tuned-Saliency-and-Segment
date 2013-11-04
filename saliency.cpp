#include <iostream>
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include "fresaliency.h"
#include "fresalgc.h"

using namespace std;
using namespace cv;

int main()
{
    Mat image;
    image = imread("./2.jpg");
    imshow("lena", image);

    FreSalGC imgSal(image);

    imgSal.segGraphCut();
    //imgSal.segMs();

    imshow("Saliency", imgSal.imgSal);
    imshow("Seg", imgSal.imgSeg);
    //imshow("Meanshift seg", imgSal.imgMs);

    waitKey(0);
    return 0;
}

