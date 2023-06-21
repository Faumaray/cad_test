cmake_minimum_required (VERSION 3.25)

project(Sandbox VERSION 0.0.1)

file(GLOB source_list "${PROJECT_SOURCE_DIR}/src/*.cpp")

set(CMAKE_CXX_FLAGS "-fPIC")

add_executable(Sandbox
    ${source_list}
)

set_target_properties (Sandbox PROPERTIES
    CXX_STANDARD 20
    CXX_EXTENSIONS OFF
)

target_compile_features(Sandbox PRIVATE cxx_std_20)

find_package(3DLibrary REQUIRED)

target_link_libraries(Sandbox PUBLIC 3DLibrary)