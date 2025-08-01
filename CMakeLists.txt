cmake_minimum_required(VERSION 3.14)
project(mini_sfm)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(${OpenCV_INCLUDE_DIRS})
find_package(OpenCV REQUIRED)

# Sources except main.cpp
file(GLOB CAMERA_SOURCES "src/*.cpp")
list(FILTER CAMERA_SOURCES EXCLUDE REGEX "main.cpp")


# Add subdirectories for modules
add_subdirectory(src/camera)
add_subdirectory(src/geometry)
add_subdirectory(src/image)
add_subdirectory(src/io/)
add_subdirectory(src/matching)
add_subdirectory(src/verification)

# Main app
add_executable(mini_sfm src/main.cpp)
target_link_libraries(mini_sfm PRIVATE camera geometry image image_loader bf_matcher geometric_verifier ${OpenCV_LIBS})


# GoogleTest support
include(GoogleTest)
enable_testing()

# Helper function to add test targets
function(add_camera_test test_name)
    add_executable(${test_name} tests/${test_name}.cpp)
    target_link_libraries(${test_name} PRIVATE camera geometry image image_loader gtest bf_matcher gtest_main geometric_verifier pthread ${OpenCV_LIBS})
    gtest_discover_tests(${test_name})
endfunction()
# Add your tests using the helper
add_camera_test(test_camera)
add_camera_test(test_keypoint)
add_camera_test(test_point3D)
add_camera_test(test_image)
add_camera_test(test_image_loader)
add_camera_test(test_bf_matcher)


file(COPY ${CMAKE_SOURCE_DIR}/tests/data/test_images 
     DESTINATION ${CMAKE_BINARY_DIR}/tests/data)
