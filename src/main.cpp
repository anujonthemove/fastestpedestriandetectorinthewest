#include <iostream>
#include <opencv2/opencv.hpp>
#include "fpdw_detector.h"

using namespace cv;

int main(int argc, char **argv)
{
    
    namedWindow("image",cv::WINDOW_NORMAL);

    fpdw::detector::FPDWDetector detector(argv[1], 50.);
    VideoCapture cap(0); // open the default camera
    if(!cap.isOpened())  // check if we succeeded
        return -1;


    for(;;)
    {
        Mat image;
        cap >> image; // get a new frame from camera

        detector.process(image);
        std::vector<Rect> rect = detector.getBBoxes();

        for(const auto &i : rect)
        {
            rectangle(image, i, Scalar(255, 0, 0), 2);
        }

        // imshow("edges", edges);
        imshow("image", image);
        if(waitKey(1) >= 0) break;
    }


    // cv::Mat image = cv::imread(argv[2]);
    
    // detector.process(image);
    // std::vector<cv::Rect> rect = detector.getBBoxes();

    // for(const auto &i : rect)
    // {
    //     cv::rectangle(image, i, cv::Scalar(255, 0, 0), 2);
    // }
    
    // cv::resize(image, image, cv::Size(image.cols*0.5, image.rows*0.5));
    // cv::imshow("image", image);
    // cv::waitKey(0);
    return 0;
}


