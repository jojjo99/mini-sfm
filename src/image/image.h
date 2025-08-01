#pragma once
#include <set>
#include <vector>
#include <array>
#include <opencv2/core.hpp>
#include <opencv2/features2d.hpp>

class Image {
    private:
        int image_id;
        std::vector<cv::KeyPoint> keypoints;
        cv::Mat descriptors;
        std::array<float, 4> qvector{};
        std::array<float, 3> tvector{};
        std::string file_path;
        cv::Matx33f intrinsics;
        cv::Size image_size;

    public:
        Image(int id, const std::string& path) : image_id(id), file_path(path) {}
        int getId() const { return image_id; }
        bool hasFeatures() const { return !keypoints.empty() && !descriptors.empty(); }

        const std::string& getFilePath() const { return file_path; }
        void setKeypoints(const std::vector<cv::KeyPoint>& kps) { keypoints = kps; }
        void setDescriptors(const cv::Mat& desc) { descriptors = desc; }

        const std::vector<cv::KeyPoint>& getKeypoints() const { return keypoints; }
        const cv::Mat& getDescriptors() const { return descriptors; }

        void setQVector(const std::array<float, 4>& q) { qvector = q; }
        const std::array<float, 4>& getQVector() const { return qvector; }    

        void setTVector(const std::array<float, 3>& t) { tvector = t; }
        const std::array<float, 3>& getTVector() const { return tvector; }

        void setIntrinsic(const cv::Matx33f &intr ) {intrinsics=intr;}
        const cv::Matx33f & getIntrinsics() const {return intrinsics;}

        void setImageSize(int width, int height){image_size=cv::Size(width, height);}
        const cv::Size& getImageSize() const {return image_size;}


};