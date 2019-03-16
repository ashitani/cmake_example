#include <stdio.h>
#include <opencv2/opencv.hpp>

int main()
{
    cv::Mat img = cv::imread("hello.png");
    cv::imshow("Hello", img);
    cv::waitKey(0);
    return 0;
}
