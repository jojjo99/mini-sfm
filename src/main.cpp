#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/features2d.hpp>
#include <filesystem>

int main() {
    std::string path = "/app/data/oxbuild_images/all_souls_000000.jpg";
    if (!std::filesystem::exists(path)) {
        std::cerr << "File does not exist: " << path << std::endl;
    }
    cv::Mat gray = cv::imread(path, cv::IMREAD_GRAYSCALE);
    if (gray.empty()) {
        std::cerr << "Failed to load image!" << std::endl;
        return -1;
    }

    // 2. Create SIFT detector
    cv::Ptr<cv::SIFT> sift = cv::SIFT::create();

    // 3. Detect and compute
    std::vector<cv::KeyPoint> keypoints;
    cv::Mat descriptors;
    sift->detectAndCompute(gray, cv::noArray(), keypoints, descriptors);

    std::cout << "Detected keypoints: " << keypoints.size() << std::endl;

    // 4. Draw keypoints
    cv::Mat output;
    cv::drawKeypoints(gray, keypoints, output, cv::Scalar(0,255,0));

    // 5. Show in window
    std::string output_path = "/app/output/keypoints.jpg";
    if (cv::imwrite(output_path, output)) {
        std::cout << "Saved keypoints visualization to " << output_path << std::endl;
    } else {
        std::cerr << "Failed to save output image!" << std::endl;
    }
    cv::waitKey(0); // Wait for a key press
    return 0;
};

