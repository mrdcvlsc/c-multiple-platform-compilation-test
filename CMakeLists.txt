cmake_minimum_required(VERSION 3.16)
project(output_binary LANGUAGES C)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

add_executable(output_binary main.c)

# links the c math library to the output binary executable
if (NOT WIN32)
    target_link_libraries(output_binary m)
endif()
