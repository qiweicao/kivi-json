cmake_minimum_required(VERSION 3.2)

project(kivi-json-project)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -O3")

set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR})

set(JSON_INSTALL_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(JSON_INSTALL_BIN_DIR ${PROJECT_SOURCE_DIR}/bin)
set(JSON_INSTALL_LIB_DIR ${PROJECT_SOURCE_DIR}/lib)

set(JSON_HEADERS_DIR ${PROJECT_SOURCE_DIR}/src/KiviJson)

include_directories(${JSON_INSTALL_INCLUDE_DIR})
include_directories(${JSON_HEADERS_DIR})

add_subdirectory(src)
# add_subdirectory(test)
