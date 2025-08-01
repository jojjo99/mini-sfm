#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/features2d.hpp>
#include <filesystem>

int main() {
    std::string path1 = "/app/tests/data/test_images/im1.jpg";
    std::string path2 = "/app/tests/data/test_images/im2.jpg";

    // 1. Load images in grayscale
    cv::Mat img1 = cv::imread(path1, cv::IMREAD_GRAYSCALE);
    cv::Mat img2 = cv::imread(path2, cv::IMREAD_GRAYSCALE);

    if (img1.empty() || img2.empty()) {
        std::cerr << "Could not load one of the images!" << std::endl;
        return -1;
    }

    // 2. Create SIFT detector
    cv::Ptr<cv::SIFT> sift = cv::SIFT::create();

    // 3. Detect and compute descriptors
    std::vector<cv::KeyPoint> kps1, kps2;
    cv::Mat desc1, desc2;
    sift->detectAndCompute(img1, cv::noArray(), kps1, desc1);
    sift->detectAndCompute(img2, cv::noArray(), kps2, desc2);

    std::cout << "Image1 keypoints: " << kps1.size() << std::endl;
    std::cout << "Image2 keypoints: " << kps2.size() << std::endl;

    // 4. Match descriptors using BFMatcher + KNN
    cv::BFMatcher matcher(cv::NORM_L2);
    std::vector<std::vector<cv::DMatch>> knn_matches;
    matcher.knnMatch(desc1, desc2, knn_matches, 2);

    // 5. Apply Lowe's ratio test
    std::vector<cv::DMatch> good_matches;
    const float ratio_thresh = 0.75f;
    for (const auto& m : knn_matches) {
        if (m.size() == 2 && m[0].distance < ratio_thresh * m[1].distance) {
            good_matches.push_back(m[0]);
        }
    }

    std::cout << "Good matches after ratio test: " << good_matches.size() << std::endl;

    // 6. Visualize matches
    cv::Mat img_matches;
    cv::drawMatches(img1, kps1, img2, kps2, good_matches, img_matches,
                    cv::Scalar::all(-1), cv::Scalar::all(-1),
                    std::vector<char>(), cv::DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS);

    // Save or display
    std::string output_path = "/app/output/matches.jpg";
    if (cv::imwrite(output_path, img_matches)) {
        std::cout << "Saved matches visualization to " << output_path << std::endl;
    } else {
        std::cerr << "Failed to save matches image!" << std::endl;
    }

    return 0;
}
