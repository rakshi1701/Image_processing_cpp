#include <opencv2/opencv.hpp>
#include <iostream>

int main(){
    std::string img_path = "data/img1.jpg";

    cv::Mat image = cv::imread(img_path);

    cv:: Mat gray, blur, edges;

    cv::resize(image, image, cv::Size(400,400));

    cv::cvtColor(image, gray, cv::COLOR_BGR2GRAY);
    cv::GaussianBlur(gray, blur, cv::Size(5, 5), 0);
    cv::Canny(blur, edges, 100, 200);

    // Find contours
    std::vector<std::vector<cv::Point>> contours;
    cv::findContours(edges, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

    // Draw results
    cv::Mat output = image.clone();

    for(const auto& contour:contours){
        double area = cv::contourArea(contour);

        // Filter small area
        if(area < 500) continue;

        cv::Rect box = cv::boundingRect(contour);
        cv::rectangle(output, box, cv::Scalar(0, 255, 0), 2);

    }

    // display result
    cv::imshow("Edges", edges);
    cv::imshow("detected objects", output);
    

    cv::waitKey(0);
    return 0;
}