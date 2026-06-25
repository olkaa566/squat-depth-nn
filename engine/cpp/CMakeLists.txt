cmake_minimum_required(VERSION 3.10)

project(SquatVisionEngine VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

add_executable(engine 
    src/main.cpp
    src/matrix.cpp
    src/vision.cpp
    src/png_decoder.cpp
)

if(MSVC)
    target_compile_options(engine PRIVATE /W4)
else()
    target_compile_options(engine PRIVATE -Wall -Wextra)
endif()