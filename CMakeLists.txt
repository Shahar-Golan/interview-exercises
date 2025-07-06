cmake_minimum_required(VERSION 3.10)
project(UnitTestExercise)
set(CMAKE_CXX_STANDARD 11)

# Library target
add_library(processor src/processor.cpp)
target_include_directories(processor PUBLIC include)

# Enable tests
option(BUILD_TESTS "Build unit tests" ON)
if(BUILD_TESTS)
  enable_testing()
  add_subdirectory(tests)
endif()
