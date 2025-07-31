#pragma once
#include "../image/image.h"
#include <vector>
#include <opencv2/core.hpp>
#include <opencv2/features2d.hpp>

class Matcher{ 
    public:
        virtual ~Matcher()=default;
        virtual std::vector<cv::DMatch> match(const Image& im1, const Image& im2) = 0;

    
};