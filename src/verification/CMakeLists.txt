add_library(geometric_verifier geometric_verifier.cpp)
target_include_directories(geometric_verifier PUBLIC src/verification )
target_link_libraries(geometric_verifier PUBLIC ${OpenCV_LIBS} )