add_library(geometry keypoint.cpp point3D.cpp)
target_include_directories(geometry PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})