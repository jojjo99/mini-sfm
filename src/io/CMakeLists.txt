add_library(image_loader image_loader.cpp)  
target_include_directories(image_loader PUBLIC src/io)
target_link_libraries(image_loader PUBLIC ${OpenCV_LIBS})