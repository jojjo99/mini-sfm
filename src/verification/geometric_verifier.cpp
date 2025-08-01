#include "geometric_verifier.h"
#include <opencv2/core.hpp>        // Core data structures (cv::Mat, cv::Point2f, etc.)
#include <opencv2/calib3d.hpp>     // findEssentialMat, recoverPose, triangulatePoints
#include <opencv2/features2d.hpp>  // KeyPoint, DMatch if you work with descriptor

// Estimate intrinsics assuming pinhole camera
cv::Mat GeometricVerifier::computeIntrinsics(const Image& img) const { 
    int W = img.getImage().cols;
    int H = img.getImage().rows;

    // Approximate focal length
    float f = static_cast<float>(std::max(W, H));
    float cx = W / 2.0f;
    float cy = H / 2.0f;

    return (cv::Mat_<double>(3,3) <<
        f, 0, cx,
        0, f, cy,
        0, 0, 1);
}

std::vector<cv::DMatch> GeometricVerifier::verify(
        const Image& img1, const Image& img2,
        const std::vector<cv::DMatch>& matches) const {

    std::vector<cv::Point2f> pts1, pts2;
    pts1.reserve(matches.size());
    pts2.reserve(matches.size());

    for(const auto& m : matches){
        pts1.push_back(img1.getKeypoints()[m.queryIdx].pt);
        pts2.push_back(img2.getKeypoints()[m.trainIdx].pt); // Must be trainIdx to access the right index
    }

    cv::Matx33f K1 = img1.getIntrinsics();
    cv::Matx33f K2 = img2.getIntrinsics();

    std::vector<cv::Point2f> pts1_norm, pts2_norm;
    pts1_norm.reserve(pts1.size());
    pts2_norm.reserve(pts2.size());
    
    // Normalize the points assuming K1, K2 different
    for (size_t i = 0; i < pts1.size(); ++i) { 
        pts1_norm.emplace_back(
            (pts1[i].x - K1(0,2))/K1(0,0),
            (pts1[i].y - K1(1,2))/K1(1,1)
        );
        pts2_norm.emplace_back(
            (pts2[i].x - K2(0,2))/K2(0,0),
            (pts2[i].y - K2(1,2))/K2(1,1)
        );
    }

    cv::Mat mask;
    cv::Mat E = cv::findEssentialMat(
        pts1_norm, pts2_norm,
        1.0, cv::Point2f(0,0),
        cv::RANSAC, 0.999, 1.0, mask
    );

    std::vector<cv::DMatch> inlier_matches;
    inlier_matches.reserve(matches.size());
    for(size_t i = 0; i < matches.size(); ++i){
        if(mask.at<uchar>(i))
            inlier_matches.push_back(matches[i]);
    }
    return inlier_matches;
}