#pragma once
#include <opencv2/opencv.hpp>

class ImageProcessor {
public:
    cv::Mat process(const cv::Mat& image);
};