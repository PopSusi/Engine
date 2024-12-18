cmake_minimum_required(VERSION 3.13)
set(CMAKE_GENERATOR_PLATFORM x64)
project(SusiMachine)

find_package(OpenGL REQUIRED)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp  # Adjust according to your file extension if needed
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/Glad/src/glad.c
)

add_executable(SusiMachine ${SOURCES})

include_directories(${SusiMachine_SOURCE_DIR}/include)
include_directories(${SusiMachine_SOURCE_DIR}/lib/Glad/include)
include_directories(${SusiMachine_SOURCE_DIR}/lib/GLFW/include)
include_directories(${SusiMachine_SOURCE_DIR}/lib/glm)
include_directories(${SusiMachine_SOURCE_DIR}/lib/SDL3/include)

target_link_libraries(SusiMachine
    ${SusiMachine_SOURCE_DIR}/lib/GLFW/lib-vc2022/glfw3.lib
    ${SusiMachine_SOURCE_DIR}/lib/GLFW/lib-vc2022/glfw3_mt.lib
    ${SusiMachine_SOURCE_DIR}/lib/GLFW/lib-vc2022/glfw3dll.lib
)