cmake_minimum_required(VERSION 3.14)
project(mini_sfm)
set(CMAKE_CXX_STANDARD 17)

# Sources except main.cpp
file(GLOB CAMERA_SOURCES "src/*.cpp")
list(FILTER CAMERA_SOURCES EXCLUDE REGEX "main.cpp")


# Add subdirectories for modules
add_subdirectory(src/camera)
add_subdirectory(src/geometry)
add_subdirectory(src/image)

# Main app
add_executable(mini_sfm src/main.cpp)
target_link_libraries(mini_sfm PRIVATE camera geometry image)


# GoogleTest support
include(GoogleTest)
enable_testing()

# Helper function to add test targets
function(add_camera_test test_name)
    add_executable(${test_name} tests/${test_name}.cpp)
    target_link_libraries(${test_name} PRIVATE camera geometry gtest gtest_main pthread)
    gtest_discover_tests(${test_name})
endfunction()

# Add your tests using the helper
add_camera_test(test_camera)
add_camera_test(test_keypoint)
add_camera_test(test_point3D)
add_camera_test(test_image)

