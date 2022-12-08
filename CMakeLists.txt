cmake_minimum_required(VERSION 3.0.0)
project(FirstCMakeProj VERSION 0.1.0)

include(CTest)
enable_testing()


project(2022)
include_directories(headers)
file(GLOB SOURCES "*.cpp")
add_executable(2022 ${SOURCES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
