#include <gtest/gtest.h>
#include "../src/geometry/point3D.h"

TEST(Point3DTest, ConstructorAndGetters){
    Point3D point (1.0, 1.0, 1.0, 1);
    EXPECT_DOUBLE_EQ(point.getX(), 1.0);
    EXPECT_DOUBLE_EQ(point.getY(), 1.0);    
    EXPECT_DOUBLE_EQ(point.getZ(), 1.0);
    EXPECT_EQ(point.getId(), 1);
}