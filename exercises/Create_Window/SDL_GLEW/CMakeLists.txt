# ---CMAKE SETUP ---
# CMake version required
cmake_minimum_required(VERSION 3.10)

# Project name
project(Window_SDL)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


# --- EXTERNAL LIBRARIES SETUP ---
find_package(SDL2 REQUIRED)
find_package(GLEW REQUIRED)

include_directories(${SDL_INCLUDE_DIRS} ${GLEW_INCLUDE_DIR})


# --- CORE PROJECT SETUP ---
# Add project source files
file(GLOB_RECURSE SOURCE_FILES
      ${CMAKE_SOURCE_DIR}/src/*c
      ${CMAKE_SOURCE_DIR}/src/*.cpp)

# Add project header files
file(GLOB_RECURSE HEADERS_FILES
      ${CMAKE_SOURCE_DIR}/src/*.h
      ${CMAKE_SOURCE_DIR}/src/*hpp)

# Specify lib directory
link_directories(${CMAKE_SOURCE_DIR}/lib)

configure_file(src/helpers/RootDir.h.in src/helpers/RootDir.h)
include_directories("${CMAKE_SOURCE_DIR}/src" "${CMAKE_SOURCE_DIR}/include")
#include_directories(${CMAKE_BINARY_DIR}/src)


# --- EXECUTABLE ---
add_executable(${PROJECT_NAME} ${HEADER_FILES} ${SOURCE_FILES})

# --- LINK LIBRARIES ---
set(LIBS SDL2 GLEW)
target_link_libraries(${PROJECT_NAME} ${LIBS})
