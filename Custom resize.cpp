void customResize(const cv::Mat& src, cv::Mat& dst, int interpolation) {
    int newWidth = src.cols / 2;
    int newHeight = src.rows / 2;
    dst = cv::Mat(newHeight, newWidth, src.type());

    // Implement nearest neighbor, bilinear, and bicubic interpolation
    if (interpolation == cv::INTER_NEAREST) {
        // Nearest neighbor implementation
    } else if (interpolation == cv::INTER_LINEAR) {
        // Bilinear interpolation implementation
    } else if (interpolation == cv::INTER_CUBIC) {
        // Bicubic interpolation implementation
    }
}

int main() {
    cv::Mat image = cv::imread("G178_2-1080.BMP");
    if (image.empty()) {
        std::cerr << "Could not open or find the image!" << std::endl;
        return -1;
    }

    cv::Mat resizedImageNearest, resizedImageLinear, resizedImageCubic;

    customResize(image, resizedImageNearest, cv::INTER_NEAREST);
    customResize(image, resizedImageLinear, cv::INTER_LINEAR);
    customResize(image, resizedImageCubic, cv::INTER_CUBIC);

    // Compare with OpenCV output
    // Measure time
    measureTime(image, cv::INTER_NEAREST, "INTER_NEAREST (custom)");
    measureTime(image, cv::INTER_LINEAR, "INTER_LINEAR (custom)");
    measureTime(image, cv::INTER_CUBIC, "INTER_CUBIC (custom)");

    return 0;
}
