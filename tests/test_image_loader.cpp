#include <gtest/gtest.h>
#include "../src/io/image_loader.h"

TEST(ImageLoaderTest, LoadImagesFromFolder) {
    ImageLoader loader;
    std::string test_folder = "./tests/data/test_images";
    loader.loadImagesFromFolder(test_folder);
    const auto& images =loader.getImages();
    EXPECT_EQ(images.size(), 2);
    const Image* img=loader.getImage(0);
    ASSERT_NE(img, nullptr);  
    EXPECT_EQ(img->getId(), 0);

    EXPECT_FALSE(img->getKeypoints().empty());  
    EXPECT_GT(img->getDescriptors().rows, 0);
}