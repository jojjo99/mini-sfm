add_library(pose_estimator pose_estimator.cpp)
target_include_directories(pose_estimator PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(pose_estimator PUBLIC ${OpenCV_LIBS} )