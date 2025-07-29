#include <gtest/gtest.h>
#include "../src/camera/camera.h"

TEST(CameraTest, ProjectSimplePoint) {
    Camera cam(100.0, 100.0, 320.0, 240.0);
    auto [u, v] = cam.project(1.0, 1.0, 1.0);
    EXPECT_NEAR(u, 420.0, 1e-5);
    EXPECT_NEAR(v, 340.0, 1e-5);
}

TEST(CameraTest, UnprojectSimplePoint) {
    Camera cam(100.0, 100.0, 320.0, 240.0);
    auto [X, Y, Z] = cam.unproject(420.0, 340.0, 1.0);
    EXPECT_NEAR(X, 1.0, 1e-5);
    EXPECT_NEAR(Y, 1.0, 1e-5);
    EXPECT_NEAR(Z, 1.0, 1e-5);
}