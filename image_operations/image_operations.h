// image_operations.h
#ifndef UTILS_H
#define UTILS_H

#include <opencv2/opencv.hpp>
#include <string>

// Loading image
cv::Mat load_image(const std::string& image_path);

// Save image
bool save_image(const std::string& output_path,
                    const cv::Mat& image);

// Display image
void display_image(const std::string& window_name, 
    const cv::Mat& image, const int wait_time = 0);

#endif // UTILS_H