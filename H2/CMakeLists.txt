MAKE_MINIMUM_REQUIRED (VERSION 3.2)
project (ProductManager)
add_executable(main main.cc
                src/Product.cc
                src/ProductManager.cc
                src/XMLHandler.cc)
target_include_directories(main PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)