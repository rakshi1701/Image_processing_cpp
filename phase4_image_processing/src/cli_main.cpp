#include <opencv2/opencv.hpp>
#include <iostream>
#include "image_processor.hpp"

int main(int argc, char** argv){
    if(argc <2){
        std::cerr << "useage: less image path\n";
        return -1;
    }

    std::string image_path = argv[1];

    cv::Mat image = cv::imread(image_path);
    if (image.empty()){
        std::cerr << "Error: could not load image: " << image_path <<"\n";
        return -1;
    }

    cv::resize(image, image, cv::Size(720, 720));
    cv::imshow("image", image);
    cv::waitKey(0);
}