#include "image_processor.hpp"

cv::Mat ImageProcessor::process(const cv::Mat& image) {
    cv::Mat gray, blurred, edges, output;

    cv::cvtColor(image, gray, cv::COLOR_BGR2GRAY);
    cv::GaussianBlur(gray, blurred, cv::Size(5, 5), 0);
    cv::Canny(blurred, edges, 100, 200);

    std::vector<std::vector<cv::Point>> contours;
    cv::findContours(edges, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

    output = image.clone();

    for (const auto& contour : contours) {
        double area = cv::contourArea(contour);
        if (area < 500) continue;

        cv::Rect box = cv::boundingRect(contour);
        cv::rectangle(output, box, cv::Scalar(0, 255, 0), 2);
    }

    return output;
}