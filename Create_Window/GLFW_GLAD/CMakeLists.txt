#https://github.com/billymosis/cpp-glfw-opengl

# Minimum version of CMake required
cmake_minimum_required(VERSION 3.10)

# Set the project name
project(Window_GLFW)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add project source files
file(GLOB_RECURSE SOURCE_FILES
      ${CMAKE_SOURCE_DIR}/src/*.c
      ${CMAKE_SOURCE_DIR}/src/*.cpp)

# Add project header files
file(GLOB_RECURSE HEADER_FILES
      ${CMAKE_SOURCE_DIR}/src/*.h
      ${CMAKE_SOURCE_DIR}/src/*.hpp)

link_directories(${CMAKE_SOURCE_DIR}/lib)

configure_file(src/helpers/RootDir.h.in src/helpers/RootDir.h)
include_directories(${CMAKE_BINARY_DIR}/src)

# External libraries in system packages
find_package(glfw3 REQUIRED)
include_directories(${GLFW3_INCLUDE_DIRS})

find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS})

include_directories("${CMAKE_SOURCE_DIR}/external/glad/include")
set(GLAD_SOURCES "${CMAKE_SOURCE_DIR}/external/glad/src/glad.c")


# Create a variable with all linking libraries
set(LIBS ${OPENGL_LIBRARIES} ${GLFW3_LIBRARIES})

# Add include directories
include_directories("${CMAKE_SOURCE_DIR}/src")

add_executable(${PROJECT_NAME} ${HEADER_FILES} ${SOURCE_FILES} ${GLAD_SOURCES})

target_link_libraries(${PROJECT_NAME} ${LIBS})
