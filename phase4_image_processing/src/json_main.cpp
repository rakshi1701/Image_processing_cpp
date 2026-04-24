// install dependencies 
//      sudo apt install nlohmann-json3-dev

#include <opencv2/opencv.hpp>
#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
#include "image_processor.hpp"

using json = nlohmann::json;

int main() {
    std::ifstream file("../config/config.json");
    if (!file.is_open()) {
        std::cerr << "Error: Could not open config file\n";
        return -1;
    }

    json config;
    file >> config;

    std::string image_path = config.value("image_path", "");
    std::string output_path = config.value("output_path", "output.jpg");
    bool save = config.value("save", false);
    bool display = config.value("display", true);

    if (image_path.empty()) {
        std::cerr << "Error: image_path missing in config\n";
        return -1;
    }

    cv::Mat image = cv::imread(image_path);
    if (image.empty()) {
        std::cerr << "Error: Could not load image\n";
        return -1;
    }

    ImageProcessor processor;
    cv::Mat result = processor.process(image);

    if (save) {
        if (!cv::imwrite(output_path, result)) {
            std::cerr << "Error: Failed to save image\n";
            return -1;
        }
        std::cout << "Saved to " << output_path << "\n";
    }

    if (display) {
        cv::imshow("Result", result);
        cv::waitKey(0);
    }

    return 0;
}