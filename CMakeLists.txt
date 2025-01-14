cmake_minimum_required(VERSION 3.13)
project(SusiMachine)

find_package(OpenGL REQUIRED)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    # Windows-specific settings
    set(CMAKE_GENERATOR_PLATFORM x64)
    add_definitions(-DPLATFORM_WINDOWS)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /DWIN32")
elseif(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    # macOS-specific settings
    add_definitions(-DPLATFORM_MAC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DAPPLE")
elseif(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    # Linux-specific settings
    add_definitions(-DPLATFORM_LINUX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DLINUX")
    # Example: Linking with X11 libraries (if needed)
    find_package(X11 REQUIRED)
    if(X11_FOUND)
        include_directories(${X11_INCLUDE_DIR})
        target_link_libraries(${PROJECT_NAME} ${X11_LIBRARIES})
    endif()
endif()

file(GLOB SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp  # Adjust according to your file extension if needed
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/Glad/src/glad.c
)

add_executable(SusiMachine ${SOURCES})

include_directories(${SusiMachine_SOURCE_DIR}/include)
include_directories(${SusiMachine_SOURCE_DIR}/lib/Glad/include)
include_directories(${SusiMachine_SOURCE_DIR}/lib/glm)


if (CMAKE_SYSTEM_NAME STREQUAL "Windows")
    include_directories(${SusiMachine_SOURCE_DIR}/lib/GLFW/include)
    include_directories(${SusiMachine_SOURCE_DIR}/lib/SDL3/include)
    include_directories(${SusiMachine_SOURCE_DIR}/lib/assimp/5.4.3/include)

    target_link_libraries(SusiMachine
        ${SusiMachine_SOURCE_DIR}/lib/GLFW/lib-vc2022/glfw3.lib
        ${SusiMachine_SOURCE_DIR}/lib/GLFW/lib-vc2022/glfw3_mt.lib
        ${SusiMachine_SOURCE_DIR}/lib/GLFW/lib-vc2022/glfw3dll.lib
    )
elseif (CMAKE_SYSTEM_NAME STREQUAL "Darwin") # macOS
    include_directories(/opt/homebrew/Cellar/glfw/3.4/include)
    target_link_libraries(SusiMachine
        /opt/homebrew/Cellar/glfw/3.4/lib/libglfw.3.dylib
        ${SusiMachine_SOURCE_DIR}/lib/assimp/5.4.3/lib/libassimp.dylib
    )
elseif (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    target_link_libraries(SusiMachine
        ${SusiMachine_SOURCE_DIR}/lib/GLFW/lib-linux/libglfw3.a
    )
endif ()