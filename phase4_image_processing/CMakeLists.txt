cmake_minimum_required(VERSION 3.16)
project(phase4_image_processing)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenCV REQUIRED)

file(COPY data DESTINATION ${CMAKE_BINARY_DIR})

# ---- phase4 ----
add_executable(phase4 
    src/main.cpp
    src/image_processor.cpp
)

target_include_directories(phase4 PRIVATE
    include
    ${OpenCV_INCLUDE_DIRS}
)

target_link_libraries(phase4 PRIVATE ${OpenCV_LIBS})

# ---- cli_image ----
add_executable(cli_image 
    src/cli_main.cpp
    src/image_processor.cpp
)

target_include_directories(cli_image PRIVATE
    include
    ${OpenCV_INCLUDE_DIRS}
)

target_link_libraries(cli_image PRIVATE ${OpenCV_LIBS})