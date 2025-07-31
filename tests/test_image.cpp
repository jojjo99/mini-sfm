#include <gtest/gtest.h>
#include "../src/image/image.h"

TEST(ImageTest, ConstructorAndGetters) {
    Image img(1, "test_image.jpg");
    EXPECT_EQ(img.getId(), 1);
}