#include <utility>
#include <tuple>
class Camera {
    private:
        double fx, fy, cx, cy; // Camera intrinsic parameters

    public:
        // Constructor to initialize camera parameters
        Camera(double fx, double fy, double cx, double cy);
        // Function to project 3D points to 2D image plane
        std::pair<double, double> project(double X, double Y, double Z) const;

        std::tuple<double, double, double> unproject(double u, double v, double depth) const;

        // Getters for camera parameters
        double getFx() const { return fx; }
        double getFy() const { return fy; }
        double getCx() const { return cx; }     
        double getCy() const { return cy; }
};