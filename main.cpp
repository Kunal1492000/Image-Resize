#include <opencv2/opencv.hpp>
#include <chrono>
#include <iostream>


void resizeImage(const cv::Mat& src, cv::Mat& dst, int interpolation) {
    cv::resize(src, dst, cv::Size(src.cols / 2, src.rows / 2), 0, 0, interpolation);
}

int main() {
    // Load the image
    cv::Mat image = cv::imread("G178_2-1080.BMP");
    if (image.empty()) {
        std::cerr << "Could not open or find the image!" << std::endl;
        return -1;
    }

    cv::Mat resizedImageNearest, resizedImageLinear, resizedImageCubic;

    // Resize using different interpolation methods
    resizeImage(image, resizedImageNearest, cv::INTER_NEAREST);
    resizeImage(image, resizedImageLinear, cv::INTER_LINEAR);
    resizeImage(image, resizedImageCubic, cv::INTER_CUBIC);

    // Save the resized images
    cv::imwrite("resized_nearest.bmp", resizedImageNearest);
    cv::imwrite("resized_linear.bmp", resizedImageLinear);
    cv::imwrite("resized_cubic.bmp", resizedImageCubic);

    return 0;
}
