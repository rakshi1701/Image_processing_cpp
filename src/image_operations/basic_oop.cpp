#include "image_operations.h"
#include <iostream>

int main(){
    std::string image_path = "data/img1.jpg";

    cv::Mat image = load_image(image_path);

    if(image.empty()){
        std::cerr << "Error: couldnot load image" << std::endl;
        return -1;
    }   
    
    display_image("Loaded Image", image);

    return 0;
}