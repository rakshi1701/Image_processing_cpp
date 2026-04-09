#include "image_operations/image_operations.h"
#include <iostream>
// #include <opencv2/opencv.hpp>


int main(){
    std::string image_path = "data/img1.jpg";

    cv::Mat resize, gray, blurred, edge;


    cv::Mat image = load_image(image_path);

    if(image.empty()){
        std::cerr << "Error: couldnot load image" << std::endl;
        return -1;
    }

    cv::resize(image, image, cv::Size(400, 400));

    cv::cvtColor(image, gray, cv::COLOR_BGR2GRAY);
    cv::GaussianBlur(gray, blurred, cv::Size(5, 5), 0);
    cv::Canny(blurred, edge, 100, 200);

    display_image("Resized Image", resize);
    display_image("Gray Image", gray);
    display_image("Blurred Image", blurred);
    display_image("Edge Image", edge);

    return 0;
}