#include <opencv2/highgui.hpp>
#include <iostream>
#include "opencv_handler.hpp"
using namespace std;
using namespace cv;

void OpencvHandler::ImageHandler::imread()
{
    this->image = cv::imread(inputfile, IMREAD_COLOR);
}

void OpencvHandler::ImageHandler::imwrite()
{
    std::cout << "writing image " << std::endl;
    cv::imwrite(outputfile, image);
}

OpencvHandler::ImageHandler::ImageHandler(std::string inputfile, std::string outputfile)
{
    this->inputfile = inputfile;
    this->outputfile = outputfile;
    this->imread();
    this->colorspace = BGR;
}

void OpencvHandler::ImageHandler::imshow()
{
    cv::imshow("Processed Image", this->image);
    cv::waitKey(0);
}

void OpencvHandler::ImageHandler::BGRtoHSV()
{
    if (this->colorspace == BGR)
    {
        cv::cvtColor(image, image, COLOR_BGR2HSV);
        this->colorspace = HSV;
    }
}

void OpencvHandler::ImageHandler::HSVtoBGR()
{
    if (this->colorspace == HSV)
    {
        cv::cvtColor(image, image, COLOR_HSV2BGR);
        this->colorspace = BGR;
    }
}

void OpencvHandler::ImageHandler::mask_by_range(int xmin, int xmax, int ymin, int ymax, int zmin, int zmax)
{
    // std::cout << " " <<xmin  << " " << ymin <<" " << zmin << " "<< xmax << " " << ymax<< " " << zmax << " " << std::endl;
    cv::Scalar min = cv::Scalar(xmin, ymin, zmin);
    cv::Scalar max = cv::Scalar(xmax, ymax, zmax);
    cv::Mat tempmask, temp;
    cv::inRange(this->image, min, max, tempmask);
    cv::bitwise_and(this->image, this->image, temp, tempmask);
    this->image = temp;
};

OpencvHandler::ImageHandler::~ImageHandler()
{
    this->HSVtoBGR();
    this->imwrite();
}