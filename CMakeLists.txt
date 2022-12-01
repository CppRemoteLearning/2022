CMAKE_MINIMUM_REQUIRED (VERSION 3.2)
project (my_first_program)
add_executable(FirstFile first_file.cc
                src/first_test_header.cc)
add_executable(SecondFile second_file.cc
                src/first_test_header.cc)
add_executable(ThirdFile third_file.cc
                src/first_test_header.cc)
target_include_directories(FirstFile PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)