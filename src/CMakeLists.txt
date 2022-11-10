project(cmake VERSION 0.0.22$ENV{TRAVIS_BUILD_NUMBER})

include_directories(${Boost_INCLUDE_DIR})

find_package(Threads REQUIRED)
find_package(Boost COMPONENTS unit_test_framework REQUIRED)
find_package(spdlog REQUIRED)

configure_file(version.h.in version.h)

if (Boost_FOUND)
    message(STATUS "Boost_INCLUDE_DIR: ${Boost_INCLUDE_DIR}")
    message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")
    message(STATUS "Boost_VERSION: ${Boost_VERSION}")

    include_directories(${Boost_INCLUDE_DIR})
endif()

add_executable(main main.cpp)

add_library(lib lib/lib.cpp)

target_include_directories(lib PUBLIC lib)

target_link_libraries(main
        lib
        Threads::Threads
        spdlog::spdlog
)

install(TARGETS main RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT 3555997@gmail.com)

set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON)

include(CPack)