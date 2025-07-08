cmake_minimum_required(VERSION 3.10)
project(UnitTestExercise)
set(CMAKE_CXX_STANDARD 11)

# Make GoogleTest use the same runtime as the rest of the project
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Fetch GoogleTest
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)
FetchContent_MakeAvailable(googletest)

# Library target
add_library(processor src/processor.cpp)
target_include_directories(processor PUBLIC include)

# Enable tests
option(BUILD_TESTS "Build unit tests" ON)
if(BUILD_TESTS)
  enable_testing()
  add_subdirectory(tests)
endif()
