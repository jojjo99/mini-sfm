#include <gtest/gtest.h>
#include "../src/matching/bf_matcher.h"
#include "../src/image/image.h"
#include "../src/io/image_loader.h"

TEST(BFMatcherTest, Match){
    ImageLoader loader;
    std::string test_folder = "./tests/data/test_images";
    loader.loadImagesFromFolder(test_folder);
    const auto& images =loader.getImages();
    const auto& img1 = images.at(0);
    const auto& img2 = images.at(1);

    BFMatcherWrapper matcher;
    auto matches = matcher.match(img1, img2);

    EXPECT_FALSE(matches.empty());  

};