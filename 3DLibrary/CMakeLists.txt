cmake_minimum_required(VERSION 3.25)
project(3DLibrary VERSION 0.0.1)

file(GLOB source_list "${PROJECT_SOURCE_DIR}/src/*.cpp")

set(CMAKE_CXX_FLAGS "-fPIC")

add_library(3DLibrary SHARED
    ${source_list}
)

set_target_properties(3DLibrary PROPERTIES
    CXX_EXTENSIONS OFF
)


target_include_directories(3DLibrary
    PUBLIC "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>")

target_compile_features(3DLibrary PRIVATE cxx_std_20)