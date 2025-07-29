#include <set>
#include <vector>
class Image {
    private:
        int image_id;
        std::set<int> keypoint_ids;
        std::vector<std::vector<float>> descriptors;
        std::vector<float> qvector;
        std::vector<float> tvector;

    public:
        Image(int id) : image_id(id) {}
        int getId() const { return image_id; }
        void addKeypointId(int keypoint_id) { keypoint_ids.insert(keypoint_id); }
        const std::set<int>& getKeypointIds() const { return keypoint_ids; }
        void addDescriptor(const std::vector<float>& descriptor) { descriptors.push_back(descriptor); }
        const std::vector<std::vector<float>>& getDescriptors() const { return descriptors; }   
        void setQVector(const std::vector<float>& q) { qvector = q; }
        const std::vector<float>& getQVector() const { return qvector; }    
        void setTVector(const std::vector<float>& t) { tvector = t; }
        const std::vector<float>& getTVector() const { return tvector; }


};