void measureTime(const cv::Mat& src, int interpolation, const std::string& method) {
    cv::Mat dst;
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < 1000; ++i) {
        cv::resize(src, dst, cv::Size(src.cols / 2, src.rows / 2), 0, 0, interpolation);
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;

    std::cout << "Time taken for 1000 iterations using " << method << " : " << duration.count() << " ms" << std::endl;
}

int main() {
    cv::Mat image = cv::imread("G178_2-1080.BMP");
    if (image.empty()) {
        std::cerr << "Could not open or find the image!" << std::endl;
        return -1;
    }

    measureTime(image, cv::INTER_NEAREST, "INTER_NEAREST");
    measureTime(image, cv::INTER_LINEAR, "INTER_LINEAR");
    measureTime(image, cv::INTER_CUBIC, "INTER_CUBIC");

    return 0;
}
