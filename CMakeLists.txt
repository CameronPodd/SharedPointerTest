cmake_minimum_required(VERSION 3.10)

project(TITLE VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)

# Enable the "make test" command
ENABLE_TESTING()

# Enable ExternalProject CMake module
include(ExternalProject)

set(EXTERNAL_INSTALL_LOCATION ${CMAKE_BINARY_DIR}/external)

ExternalProject_Add(googletest
    GIT_REPOSITORY https://github.com/google/googletest
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${EXTERNAL_INSTALL_LOCATION}
)

include_directories(${EXTERNAL_INSTALL_LOCATION}/include)
link_directories(${EXTERNAL_INSTALL_LOCATION}/lib)

# Add test executable target
add_subdirectory(src EXE)
add_subdirectory(test TESTS)
