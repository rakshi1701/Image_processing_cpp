#include <opencv2/opencv.hpp>
#include <iostream>
#include "image_processor.hpp"

int main() {
    cv::Mat image = cv::imread("data/img1.jpg");

    if (image.empty()) {
        std::cerr << "Error loading image\n";
        return -1;
    }

    cv::resize(image, image, cv::Size(720, 720));

    ImageProcessor processor;
    cv::Mat result = processor.process(image);

    cv::imshow("Result", result);
    cv::waitKey(0);

    return 0;
}