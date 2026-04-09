#include <opencv2/opencv.hpp>
#include <iostream>

int main(){
    // std::string image_path = "data/img1.jpg";
    std::string image_path;
    std::cout << "enter image path: "<<std::endl;
    std::cin >> image_path;

    cv::Mat image = cv::imread(image_path);

    if (image.empty()){
        std::cerr << "Error: Couldnot load image" << std::endl;
        return -1;
    }

    std::cout << "Width:" << image.cols <<std::endl;
    std::cout << "Height:" << image.rows <<std::endl;
    std::cout << "Channels:" << image.channels() <<std::endl;

    cv::Mat resized_image;
    cv::resize(image, resized_image, cv::Size(400, 400));

    cv::Mat gray_image;
    cv::cvtColor(resized_image, gray_image, cv::COLOR_BGR2GRAY);

    // Save image
    cv::imwrite("data/resized_image.jpg", resized_image);

    cv::imshow("Original Image", image);
    cv::imshow("Resized Image", resized_image);
    cv::imshow("Gray image", gray_image);

    cv::waitKey(0);
    return 0;
}