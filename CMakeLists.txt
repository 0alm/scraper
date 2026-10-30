cmake_minimum_required(VERSION 3.20)
project(scraper LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
find_package(CURL REQUIRED)
add_executable(
    scaper
    src/logic/scrap/scrap.cpp
    src/logic/send/send.cpp
)
target_include_directories(scaper PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/config
)
target_link_libraries(scaper PRIVATE CURL::libcurl)