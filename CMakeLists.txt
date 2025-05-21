cmake_minimum_required(VERSION 3.25)
project(indicate LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_CXX_SCAN_FOR_MODULES ON)
set(CMAKE_EXPERIMENTAL_CXX_MODULE_CMAKE_API ON)

# Option for examples/tests
option(BUILD_EXAMPLES "Build example executables" ON)
#option(BUILD_TESTS    "Build unit tests"       OFF)

# Always build the library
add_subdirectory(src)

# Conditionally build examples & tests
if (BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()

#if (BUILD_TESTS)
#    enable_testing()
#    add_subdirectory(tests)
#endif()
