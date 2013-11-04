#include "fresaliency.h"

void FreSaliency::calSal()
{
    // GaussianBlur
    GaussianBlur(imgLab, gaussImg, Size(3, 3), 0, 0);

    // Mean value of L*A*B
    CvScalar meanChannels = mean(gaussImg);
    double meanL = meanChannels.val[0];
    double meanA = meanChannels.val[1];
    double meanB = meanChannels.val[2];

    imgSal = Mat(imgLab.size(), CV_32FC1);

    int rows = imgSal.rows;
    int cols = imgSal.cols;

    for(int i=0; i < rows; i++)
    {
        for(int j=0; j < cols; j++)
        {
            Vec3i iLab = gaussImg.at<Vec3b>(i,j);
            imgSal.at<float>(i,j) = (float(iLab.val[0]) - meanL)*(float(iLab.val[0]) - meanL) +
                    (float(iLab.val[1]) - meanA)*(float(iLab.val[1]) - meanA) +
                    (float(iLab.val[2]) - meanB)*(float(iLab.val[2]) - meanB);
        }
    }
    normalize(imgSal, imgSal, 1.0, 0.0, NORM_MINMAX);

}

void FreSaliency::segMs()
{
    int spatialRad=25,colorRad=45,maxPryLevel=1;
    pyrMeanShiftFiltering(imgRGB, imgMs, spatialRad, colorRad, maxPryLevel);
}

FreSaliency::~FreSaliency()
{
}
