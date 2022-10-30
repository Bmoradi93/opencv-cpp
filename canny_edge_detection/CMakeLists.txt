set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set (CMAKE_CXX_STANDARD 11)
cmake_minimum_required(VERSION 3.0)

get_filename_component(ProjectId ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" ProjectId ${ProjectId})

project(${ProjectId})

file(GLOB project_sources src/*.cpp)
file(GLOB project_headers src/*.h src/*.hpp)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

# add_executable(opencvTest main.cpp)

add_executable(${ProjectId} ${project_sources} ${project_headers})
target_link_libraries(${ProjectId} ${OpenCV_LIBS})