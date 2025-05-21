add_library(indicate STATIC)

target_sources(indicate
        PUBLIC
        FILE_SET cxx_modules
        TYPE CXX_MODULES
        BASE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}
        FILES
        indicate.cppm
        indicate.progress_bar.cppm
        indicate.spinner.cppm
        indicate.human_format.cppm
        indicate.style.cppm
        indicate.util.cppm
)

# Make the module files visible to dependents
target_include_directories(indicate
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)
