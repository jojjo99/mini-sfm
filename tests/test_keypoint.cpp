#include <gtest/gtest.h>
#include "../src/geometry/keypoint.h"

TEST(KeypointTest, ConstructorsAndGetters) {
    Keypoint kp(100.0, 200.0, 1, 42);
    EXPECT_DOUBLE_EQ(kp.getX(), 100.0);
    EXPECT_DOUBLE_EQ(kp.getY(), 200.0);
    EXPECT_EQ(kp.getImageId(), 1);
    EXPECT_EQ(kp.getKeypointId(), 42);
}

TEST(KeypointTest, DistanceTo){
    Keypoint kp1(5, 12, 1, 42);
    Keypoint kp2(0, 0, 1, 43);
    EXPECT_DOUBLE_EQ(kp1.distanceTo(kp2), 13.0);
}