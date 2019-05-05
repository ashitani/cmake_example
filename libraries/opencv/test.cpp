#include <opencv2/opencv.hpp>

int main()
{
    cv::Mat img = cv::imread("../../../data/cmake.png");
    cv::imshow("Hello", img);
    cv::waitKey(0);
    return 0;
}
