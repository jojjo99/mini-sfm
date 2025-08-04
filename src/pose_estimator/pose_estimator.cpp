#include "pose_estimator.h"
std::pair<cv::Mat, cv::Mat> PoseEstimator::estimateRelativePose(Image& img1, Image& img2, std::vector<cv::DMatch>& inlier_matches) const
    {
    // Copied from geometric verification
    std::vector<cv::Point2f> pts1, pts2;

    for(const auto& m : inlier_matches){
        pts1.push_back(img1.getKeypoints()[m.queryIdx].pt);
        pts2.push_back(img2.getKeypoints()[m.trainIdx].pt); // Must be trainIdx to access the right index
    }

    cv::Matx33f K1 = img1.getIntrinsics();
    cv::Matx33f K2 = img2.getIntrinsics();

    std::vector<cv::Point2f> pts1_norm, pts2_norm;
    pts1_norm.reserve(pts1.size());
    pts2_norm.reserve(pts2.size());
    
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
    cv::Mat R, t;
    cv::recoverPose(E, pts1_norm, pts2_norm, R, t, 1.0, cv::Point2f(0,0), mask);

    return {R, t};

}