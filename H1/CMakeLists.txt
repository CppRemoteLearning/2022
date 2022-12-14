CMAKE_MINIMUM_REQUIRED (VERSION 3.2)
project (my_first_program)
add_executable(main main.cc
                src/first_test_header.cc
                src/second_test_header.cc)
target_include_directories(main PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)