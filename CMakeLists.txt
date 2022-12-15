cmake_minimum_required(VERSION 3.22)

project(tema2)
add_executable(tema2 main.cpp product.cpp store.cpp XMLObject.cpp)

include_directories(/usr/include/rapidxml)


find_library(RAPIDXML_LIB rapidXML NAMES rapidXML librapidxml-dev rapidxml)
if (RAPIDXML_LIB)
    message(FATAL_ERROR "XML library not found")
else()
    message(STATUS "library found")
endif()

add_library(RAPIDXML_LIB INTERFACE)
target_include_directories(RAPIDXML_LIB INTERFACE /usr/include)
target_link_libraries(tema2 PRIVATE RAPIDXML_LIB)