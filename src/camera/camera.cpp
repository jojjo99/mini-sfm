#include "camera.h"
#include <tuple>
#include <stdexcept> 

Camera::Camera(double fx, double fy, double cx, double cy)
    : fx(fx), fy(fy), cx(cx), cy(cy) {}

std::pair<double, double> Camera::project(double X, double Y, double Z) const {
    if(Z==0) {
        throw std::invalid_argument("Depth Z cannot be zero for projection.");
    }
    double u = fx*(X/Z)+cx;
    double v = fy*(Y/Z)+cy;
    return std::make_pair(u,v);
};

std::tuple<double, double, double> Camera::unproject(double u, double v, double depth) const {
    double X = (u-cx)*depth/fx;
    double Y = (v-cy)*depth/fy;
    return std::make_tuple(X, Y, depth);
}


