#include <vector>
#include <cmath>
class Keypoint {
    private:
        double x,y;
        int image_id;
        int keypoint_id;
        std::vector<float> descriptor;

    public:
        Keypoint(double x, double y, int image_id, int keypoint_id);
        double getX() const { return x; }
        double getY() const { return y; }   
        int getImageId() const { return image_id; }
        int getKeypointId() const { return keypoint_id; }
        const std::vector<float>& getDescriptor() const { return descriptor; }
        void setDescriptor(const std::vector<float>& desc){descriptor = desc; }
        void setX(double x) { this->x = x; }
        void setY(double y) {this->y = y; }
        void setImageId(int id) { image_id = id; }
        void setKeypointId(int id) { keypoint_id = id; }

        float distanceTo(const Keypoint& other) const {
            return std::sqrt(std::pow(x-other.x, 2)+std::pow(y-other.y, 2));
        }
};