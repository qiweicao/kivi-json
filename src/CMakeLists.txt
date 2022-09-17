cmake_minimum_required(VERSION 3.2)
project(kivi-json-main)

add_subdirectory(KiviJson)
set(SOURCE_FILES main.cpp)

add_executable(kivi-json-main ${SOURCE_FILES})
target_link_libraries(kivi-json-main kivi-json)
install(TARGETS kivi-json-main DESTINATION ${JSON_INSTALL_BIN_DIR})