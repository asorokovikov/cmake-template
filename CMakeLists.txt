cmake_minimum_required(VERSION 3.23)

if (NOT DEFINED ENV{BUILD_NUMBER})
    set(ENV{BUILD_NUMBER} 1)
endif()

project(cmake-project-template VERSION 0.0.$ENV{BUILD_NUMBER})

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED  ON)
#set(CMAKE_CXX_EXTENSIONS OFF)

if ( CMAKE_COMPILER_IS_GNUCC )
    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic")
endif()
if ( MSVC )
    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} /W4")
endif()

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

message(STATUS "Build: $ENV{BUILD_NUMBER}")

enable_testing()

add_subdirectory(src)
add_subdirectory(tests)