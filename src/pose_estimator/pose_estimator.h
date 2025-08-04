#pragma once
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>    
#include <opencv2/imgcodecs.hpp>  
#include <opencv2/imgproc.hpp>  
#include <opencv2/calib3d.hpp>   
#include <vector>
#include "../image/image.h"
#include <utility>  // for std::pair
class PoseEstimator {
    public:
        // Estimate relative pose
        std::pair<cv::Mat, cv::Mat> estimateRelativePose(
            Image& img1,
            Image& img2,
            std::vector<cv::DMatch>& inlier_matches) const;

};