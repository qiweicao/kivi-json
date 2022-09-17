cmake_minimum_required(VERSION 3.2)

project(kivi-json C CXX)

set(SOURCE_FILES
    KiviJson.h
    KiviJson.cpp
)

add_library(kivi-json SHARED STATIC ${SOURCE_FILES})

install(TARGETS kivi-json DESTINATION ${JSON_INSTALL_LIB_DIR})
install(FILES KiviJson.h DESTINATION ${JSON_INSTALL_INCLUDE_DIR})