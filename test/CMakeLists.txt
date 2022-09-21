cmake_minimum_required(VERSION 3.2)
project(kivi-json-tests)

add_subdirectory(lib/googletest)

include_directories(${JSON_HEADERS_DIR})
include_directories(lib/googletest/googletest/include)

set(SOURCE_FILES main.cpp src/tests.cpp)

add_executable(kivi-json-tests ${SOURCE_FILES})
target_link_libraries(kivi-json-tests kivi-json gtest)
install(TARGETS kivi-json-tests DESTINATION bin)