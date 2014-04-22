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
    image = imread("./moondark.jpg");
    imshow("lena", image);

    FreSalGC imgSal(image);

    imgSal.segGraphCut();
    //imgSal.segMs();

    imshow("Saliency", imgSal.imgSal);
    normalize(imgSal.imgSal, imgSal.imgSal, 255, 0, NORM_MINMAX);
	imwrite("moondark-sal.png", imgSal.imgSal);
    imshow("Seg", imgSal.imgSeg);
	imwrite("moondark-seg.png", imgSal.imgSeg);
    //imshow("Meanshift seg", imgSal.imgMs);

    waitKey(0);
    return 0;
}

