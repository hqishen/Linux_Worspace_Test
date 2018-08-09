
cmake_minimum_required(VERSION 2.6)

project(xml_doc)

include_directories("/usr/include/libxml2")

set(SRC_F
    test_main.cpp
    xmlDocumentHandle.cpp)

set(CMAKE_CXX_FLAGS "-std=c++11")

set(exe_name "xmlText")

add_executable(${exe_name} ${SRC_F})

target_link_libraries(${exe_name} xml2)
