#include(FetchContent)
#
#FetchContent_Declare(
#        googletest
#        GIT_REPOSITORY https://github.com/google/googletest.git
#        GIT_TAG        release-1.12.1
#)
#FetchContent_MakeAvailable(googletest)
#add_library(GTest::GTest INTERFACE IMPORTED)
#target_link_libraries(GTest::GTest INTERFACE gtest_main)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
find_package(GTest REQUIRED)

if (GTest_FOUND)
    message(STATUS "GTest_SOURCE_DIR: ${gtest_SOURCE_DIR}")
endif()


add_executable(lib_tests lib_tests.cpp)

target_link_libraries(lib_tests
        PRIVATE
        GTest::GTest
        lib
)

add_test(lib_tests ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/lib_tests)