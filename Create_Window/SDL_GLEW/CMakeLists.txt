# Minimum version of CMake required
cmake_minimum_required(VERSION 3.10)

# Set the project name
project(Window_SDL)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add project source files
file(GLOB_RECURSE SOURCE_FILES
      ${CMAKE_SOURCE_DIR}/src/*c
      ${CMAKE_SOURCE_DIR}/src/*.cpp)

# Add project header files
file(GLOB_RECURSE HEADERS_FILES
      ${CMAKE_SOURCE_DIR}/src/*.h
      ${CMAKE_SOURCE_DIR}/src/*hpp)

link_directories(${CMAKE_SOURCE_DIR}/lib)

configure_file(src/helpers/RootDir.h.in src/helpers/RootDir.h)
include_directories(${CMAKE_BINARY_DIR}/src)

add_executable(${PROJECT_NAME} ${HEADER_FILES} ${SOURCE_FILES})

# External libraries
find_package(SDL2 REQUIRED)
find_package(GLEW REQUIRED)

include_directories(${SDL_INCLUDE_DIRS} ${GLEW_INCLUDE_DIR})
include_directories("${CMAKE_SOURCE_DIR}/src" "${CMAKE_SOURCE_DIR}/include")

set(LIBS SDL2 GLEW)
target_link_libraries(${PROJECT_NAME} ${LIBS})
