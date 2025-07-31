add_library(bf_matcher bf_matcher.cpp)
target_include_directories(bf_matcher PUBLIC src/matching)
target_link_libraries(bf_matcher PUBLIC ${OpenCV_LIBS})