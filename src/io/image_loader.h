#include <string>
#include <vector>
#include "../image/image.h"
#include <unordered_map>
class ImageLoader {
    private:
        std::string folder_path;
        std::unordered_map<int, Image> images_;

    public:
        ImageLoader()=default;
        void loadImagesFromFolder(const std::string& folder_path);
        const Image* getImage(int image_id) const;
        const std::unordered_map<int, Image>& getImages() const { return images_; }
};