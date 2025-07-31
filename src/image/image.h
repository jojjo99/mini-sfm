#include <set>
#include <vector>
#include <opencv2/core.hpp>
#include <opencv2/features2d.hpp>

class Image {
    private:
        int image_id;
        std::vector<cv::KeyPoint> keypoints;
        cv::Mat descriptors;
        std::vector<float> qvector;
        std::vector<float> tvector;
        std::string file_path;

    public:
        Image(int id, const std::string& path) : image_id(id), file_path(path) {}
        int getId() const { return image_id; }
        bool hasFeatures() const { return !keypoints.empty() && !descriptors.empty(); }

        const std::string& getFilePath() const { return file_path; }
        void setKeypoints(const std::vector<cv::KeyPoint>& kps) { keypoints = kps; }
        void setDescriptors(const cv::Mat& desc) { descriptors = desc; }

        const std::vector<cv::KeyPoint>& getKeypoints() const { return keypoints; }
        const cv::Mat& getDescriptors() const { return descriptors; }

        void setQVector(const std::vector<float>& q) { qvector = q; }
        const std::vector<float>& getQVector() const { return qvector; }    

        void setTVector(const std::vector<float>& t) { tvector = t; }
        const std::vector<float>& getTVector() const { return tvector; }


};