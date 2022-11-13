cmake_minimum_required(VERSION 3.23)

# libboost-system-dev
find_package(Boost COMPONENTS system REQUIRED)
find_package(Threads REQUIRED)
find_package(spdlog REQUIRED)

configure_file(${PROJECT_SOURCE_DIR}/src/lib/version.h.in ${PROJECT_SOURCE_DIR}/src/lib/version.h)

if (Boost_FOUND)
    message(STATUS "Boost_INCLUDE_DIR: ${Boost_INCLUDE_DIR}")
    message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")
    message(STATUS "Boost_VERSION: ${Boost_VERSION}")

    include_directories(${Boost_INCLUDE_DIR})
endif()

add_executable(main main.cpp)

add_executable(sync_server sync_server.cpp)
target_link_libraries(sync_server
        Threads::Threads
        spdlog::spdlog
)

add_executable(resolver resolver.cpp)
target_link_libraries(resolver
        Threads::Threads
        spdlog::spdlog
)

add_executable(sync_client sync_client.cpp)
target_link_libraries(sync_client
        Threads::Threads
        spdlog::spdlog
)
#add_executable(chat_server chat_server.cpp)
#add_executable(chat_client chat_client.cpp)
#add_executable(asiohiper asiohiper.cpp)

#set_target_properties(sync_client sync_server resolver chat_server chat_client asiohiper
#        CXX_STANDARD 20
#        CXX_STANDARD_REQUIRED  ON
#)

add_library(lib lib/lib.cpp)

target_include_directories(lib PUBLIC lib)

target_link_libraries(main
        lib
        Threads::Threads
        spdlog::spdlog
)

add_executable(asio asio.cpp)
target_link_libraries(asio
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