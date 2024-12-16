# Reference: https://github.com/billymosis/cpp-glfw-opengl

# --- CMAKE SETUP ---
# CMake version requried
cmake_minimum_required(VERSION 3.10)

# Project name
project(Window_GLFW)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


# --- SETUP OPENGL ---
find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS})
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


# --- SETUP GLFW ---
# Set GLFW options
set(GLFW_BUILD_DOCS OFF CACHE BOOL "GLFW lib only")
set(GLFW_INSTALL OFF CACHE BOOL "GLFW lib only")

# Include GLFW
add_subdirectory(external/glfw)
#include_directories("${CMAKE_SOURCE_DIR}/external/GLFW/include")


# --- SETUP GLAD ---
include_directories("${CMAKE_SOURCE_DIR}/external/glad/include")
set(GLAD_SOURCES "${CMAKE_SOURCE_DIR}/external/glad/src/glad.c")


# --- CORE PROJECT SETUP ---
# Add project source files
file(GLOB_RECURSE SOURCE_FILES
      ${CMAKE_SOURCE_DIR}/src/*.c
      ${CMAKE_SOURCE_DIR}/src/*.cpp)

# Add project header files
file(GLOB_RECURSE HEADER_FILES
      ${CMAKE_SOURCE_DIR}/src/*.h
      ${CMAKE_SOURCE_DIR}/src/*.hpp)

# Specify lib directory
link_directories(${CMAKE_SOURCE_DIR}/lib)

configure_file(src/helpers/RootDir.h.in src/helpers/RootDir.h)
include_directories(${CMAKE_BINARY_DIR}/src)


# --- EXECUTABLE ---
add_executable(${PROJECT_NAME} ${HEADER_FILES} ${SOURCE_FILES} ${GLAD_SOURCES})


# --- LINK LIBRARIES ----
target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} glfw)
