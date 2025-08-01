#pragma once
#include "matcher.h"
#include <opencv2/features2d.hpp>

class BFMatcherWrapper : public Matcher {
public:
    std::vector<cv::DMatch> match(const Image& img1, const Image& img2) override;
};