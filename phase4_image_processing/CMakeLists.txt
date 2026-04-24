# cmake_minimum_required(VERSION 3.16)
# project(phase4_image_processing)

# set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)

# find_package(OpenCV REQUIRED)

# include_directories(include)

# file(COPY data DESTINATION ${CMAKE_BINARY_DIR})

# # file(GLOB SRC_FILES src/*.cpp)

# # add_executable(phase4 ${SRC_FILES})

# add_executable(phase4 
#     src/image_processor.cpp
#     src/main.cpp
#     )

# add_executable(cli_image 
#     src/image_processor.cpp
#     src/cli_main.cpp
#     )
# target_link_libraries(phase4 ${OpenCV_LIBS})

cmake_minimum_required(VERSION 3.16)
project(phase4_image_processing)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenCV REQUIRED)

file(COPY data DESTINATION ${CMAKE_BINARY_DIR})
file(COPY config DESTINATION ${CMAKE_BINARY_DIR})

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

# -----json execution--------------
find_package(nlohmann_json REQUIRED)

add_executable(json_exe
    src/json_main.cpp
    src/image_processor.cpp
    )
target_include_directories(json_exe PRIVATE
    include
    ${OpenCV_INCLUDE_DIRS}
    )
target_link_libraries(json_exe
    PRIVATE
    nlohmann_json::nlohmann_json
    ${OpenCV_LIBS}
    )