#include <vector>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>    
#include <opencv2/imgcodecs.hpp>  
#include <opencv2/imgproc.hpp>   
#include "../image/image.h"

class GeometricVerifier  {

    public:
        std::vector<cv::DMatch> verify(const Image& img1, const Image& img2, const std::vector<cv::DMatch>& matches) const;

    private:
        cv::Mat computeIntrinsics(const Image& img) const;
};