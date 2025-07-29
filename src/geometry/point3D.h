
#include <vector>
class Point3D{
    private:
        double x, y, z;
        int id;
        std::vector<int> image_ids;
        std::vector<int> keypoint_ids;

    public:
        Point3D(double x, double y, double z, int id);
        double getX() const {return x; }
        double getY() const {return y; }
        double getZ() const {return z; }
        int getId() const {return id; }
        const std::vector<int>& getImageIds() const {return image_ids;}
        const std::vector<int>& getKeypointIds() const {return keypoint_ids; }
        void addImageId(int image_id) { image_ids.push_back(image_id); }
        void addKeypointId(int keypoint_id) { keypoint_ids.push_back(keypoint_id); }
        void setX(double x) { this->x = x; }    
        void setY(double y) { this->y = y; }
        void setZ(double z) { this->z = z; }

};
