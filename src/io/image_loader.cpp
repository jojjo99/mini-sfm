
#include "image_loader.h"
#include <filesystem>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>    
#include <opencv2/imgcodecs.hpp>  
#include <opencv2/imgproc.hpp>    
namespace fs = std::filesystem;

void ImageLoader::loadImagesFromFolder(const std::string& folder_path) {
    this->folder_path = folder_path;
    images_.clear();
    int current_id = 0;
    cv::Ptr<cv::SIFT> sift = cv::SIFT::create();
    for (const auto& entry : fs::directory_iterator(folder_path)) {
        if (entry.is_regular_file() && entry.path().extension() == ".jpg") {
            cv::Mat img=cv::imread(entry.path().string(), cv::IMREAD_COLOR);
            if (img.empty()) {
                throw std::runtime_error("Failed to load image: " + entry.path().string());
            }
            cv::Mat gray;
            cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);
 
            std::vector<cv::KeyPoint> keypoints;
            cv::Mat descriptors;
            sift->detectAndCompute(gray, cv::noArray(), keypoints, descriptors);

            Image image(current_id, entry.path().string());
            image.setDescriptors(descriptors);
            image.setKeypoints(keypoints);
            images_.emplace(current_id, std::move(image));
            current_id++;
        }
    }

};

const Image* ImageLoader::getImage(int image_id) const {
    auto it = images_.find(image_id);
    if (it != images_.end()){
        return &(it->second);
    }else {
        throw std::out_of_range("Image ID not found");
    }
};
