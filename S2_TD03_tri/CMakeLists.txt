cmake_minimum_required(VERSION 3.20)

# Set the project name
project(TDO2)

# Choose your C++ version
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS OFF)

# Find all source files beginning with ex*.cpp
file(GLOB EX_SOURCES "src/ex*.cpp")

# Include the utils.cpp file
set(UTILS_SOURCE "src/utils.cpp")

set(ScopedTimer "src/ScopedTimer.hpp")

# Loop through each ex*.cpp file and create an executable
foreach(SOURCE_FILE ${EX_SOURCES})
    get_filename_component(EXECUTABLE_NAME ${SOURCE_FILE} NAME_WE)
    add_executable(${EXECUTABLE_NAME} ${SOURCE_FILE} ${UTILS_SOURCE} ${ScopedTimer})
    target_include_directories(${EXECUTABLE_NAME} PRIVATE src)
endforeach()