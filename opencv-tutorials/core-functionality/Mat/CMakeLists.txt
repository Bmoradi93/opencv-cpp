set (CMAKE_CXX_STANDARD 11)
cmake_minimum_required(VERSION 3.15)

get_filename_component(ProjectId ${CMAKE_CURRENT_SOURCE_DIR} NAME)

string(REPLACE " " "_" ProjectId ${ProjectId})

project(${ProjectId} VERSION 1.0)

# configure_file("${PROJECT_SOURCE_DIR}/projectConfig.h.in" 
#                "${PROJECT_BINARY_DIR}/projectConfig.h")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

find_package(OpenCV REQUIRED)

# include_directories(include)

file(GLOB project_sources src/*.cpp)
file(GLOB project_headers src/*.h src/*.hpp)

add_executable(${ProjectId} ${project_sources} ${project_headers})
include_directories(${OpenCV_INCLUDE_DIRS} include)


target_include_directories(${PROJECT_NAME} 
    PUBLIC ${PROJECT_BINARY_DIR})

# target_include_directories(${PROJECT_NAME} 
#     PUBLIC print_libraries/include 
#     PUBLIC external/glfw/include)

# target_link_directories(${PROJECT_NAME} 
#     PRIVATE print_libraries
#     PRIVATE external/glfw)

# target_link_libraries(${PROJECT_NAME} printer glfw ${myglewlib})

target_link_libraries(${ProjectId} ${OpenCV_LIBS})



install(TARGETS ${PROJECT_NAME} DESTINATION bin)
# install(FILES "${PROJECT_BINARY_DIR}/projectConfig.h" DESTINATION include)


include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set(CPACK_PACKAGE_VERSION_MAJOR "1")
set(CPACK_PACKAGE_VERSION_MINOR "0")
include(CPack)
