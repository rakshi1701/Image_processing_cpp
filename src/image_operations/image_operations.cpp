#include "image_operations.h"
#include <iostream>


// Loading image
cv::Mat load_image(const std::string& image_path){
    cv::Mat image = cv::imread(image_path);

    if(image.empty()){
        std::cerr << "Error: couldnot load image" << std::endl;
        return cv::Mat();
    }
    return image;
}


// Saving image
bool save_image(const std::string& output_path, const cv::Mat& image){
    if(image.empty()){
        std::cerr << "Error: couldnot save iamge" << std::endl;
        return false;
    }
    return cv::imwrite(output_path, image);
}

// Display image
void display_image(const std::string& window_name, const cv::Mat& image, const int wait_key){
    if(image.empty()){
        std::cerr << "Error: couldnot display iamge" << std::endl;
        return;
    }
    cv::imshow(window_name, image);
    cv::waitKey(wait_key);
}
