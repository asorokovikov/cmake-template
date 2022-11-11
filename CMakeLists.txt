cmake_minimum_required(VERSION 3.23)

project(CMakeTemplate VERSION 0.0.1$ENV{TRAVIS_BUILD_NUMBER})

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED  ON)
set(CMAKE_CXX_EXTENSIONS OFF)

enable_testing()

add_subdirectory(src)
add_subdirectory(tests)