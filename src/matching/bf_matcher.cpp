#pragma once
#include "bf_matcher.h"
#include <opencv2/features2d.hpp>

std::vector<cv::DMatch> BFMatcherWrapper::match(const Image& img1, const Image& img2){
            cv::BFMatcher matcher(cv::NORM_L2);
            std::vector<std::vector<cv::DMatch>> knn_matches;
            matcher.knnMatch(img1.getDescriptors(), img2.getDescriptors(), knn_matches, 2); // two NN for ratio test later

            // Ratio test
            std::vector<cv::DMatch> good_matches;
            const float ratio_thres=0.75f;
            for(const auto& m : knn_matches){
                if (m.size() == 2 && m[0].distance < ratio_thres*m[1].distance){
                    good_matches.push_back(m[0]);
                }
            
            }
            return good_matches;
        };