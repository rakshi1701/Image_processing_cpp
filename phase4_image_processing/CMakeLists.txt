cmake_minimum_required(VERSION 3.16)
project(phase4_image_processing)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenCV REQUIRED)

include_directories(include)

file(COPY data DESTINATION ${CMAKE_BINARY_DIR})

file(GLOB SRC_FILES src/*.cpp)

add_executable(phase4 ${SRC_FILES})
target_link_libraries(phase4 ${OpenCV_LIBS})