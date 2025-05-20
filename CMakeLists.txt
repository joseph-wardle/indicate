cmake_minimum_required(VERSION 3.25)
project(indicate LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(indicate STATIC)


target_sources(indicate
    PUBLIC
        FILE_SET cxx_modules
            TYPE CXX_MODULES
            BASE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/src
            FILES
                src/indicate.cppm
                src/progress_bar.cppm
                src/spinner.cppm
)
