cmake_minimum_required(VERSION 3.10)

# Project name
project(OpenCV_Project)

# use C++ 17
set(CMAKE_CXX_STANDARD 17)

# FIND OPENCV
find_package(OpenCV REQUIRED)

# Include header files
include_directories(src/include)

# Copy data foldet to build
file(COPY src/data DESTINATION ${CMAKE_BINARY_DIR})

# Add executable
add_executable(oop_image
    src/image_operations/basic_oop.cpp
    src/image_operations/image_operations.cpp
    )


target_include_directories(oop_image PRIVATE src/include)

# Link OpenCV
target_link_libraries(oop_image ${OpenCV_LIBS})