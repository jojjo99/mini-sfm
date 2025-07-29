
#include "image_loader.h"
#include <filesystem>
namespace fs = std::filesystem;

void ImageLoader::loadImagesFromFolder(const std::string& folder_path) {
    this->folder_path = folder_path;
    images_.clear();
    int current_id = 0;
    for (const auto& entry : fs::directory_iterator(folder_path)) {
        if (entry.is_regular_file() && entry.path().extension() == ".jpg") {
            Image image(current_id);
            images_[current_id] = image;
            current_id++;
        }
    }
};

const Image* ImageLoader::getImage(int image_id) const {
    auto it = images_.find(image_id);
    if (it != images_.end()){
        return &(it->second);
    }else {
        throw std::out_of_range("Image ID not found");
    }
};

const std::unordered_map<int, Image>& ImageLoader::getImages() const {
    return images_;
};