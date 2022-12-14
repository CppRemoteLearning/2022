cmake_minimum_required(VERSION 3.22)


include_directories(/usr/include/rapidxml)


#include_directories(${rapidxml_INCLUDE_DIRS})


find_library(rapidxml rapidxml NAMES rapidXML librapidxml-dev)
if (NOT ${rapidxml})
    message(STATUS "library found")
else()
    message(FATAL_ERROR "XML library not found")
endif()

project(tema2)
add_executable(tema2 main.cpp product.cpp store.cpp XMLObject.hpp)