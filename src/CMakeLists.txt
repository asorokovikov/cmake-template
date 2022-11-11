

configure_file(${PROJECT_SOURCE_DIR}/src/lib/version.h.in ${PROJECT_SOURCE_DIR}/src/lib/version.h)

find_package(Threads REQUIRED)
#find_package(Boost COMPONENTS unit_test_framework REQUIRED)
find_package(spdlog REQUIRED)

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

set(CPACK_OUTPUT_FILE_PREFIX packages)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT 3555997@gmail.com)

set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON)

include(CPack)