CXX = g++
SRCS = src/main.cpp src/Shader.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = main

INCLUDE_DIRS = -I. -Iinclude -IC:\lib\Glad\include -IC:\lib\GLFW\include -IC:\lib\SDL3\include
LIBRARY_DIRS = -LC:\lib
LIBS = -lglfw

CXXFLAGS = -std=c++17 $(INCLUDE_DIRS)
LDFLAGS = $(LIBRARY_DIRS) $(LIBS)

$(TARGET): $(OBJS)
    $(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET) $(LDFLAGS)

%.o: %.cpp
    $(CXX) $(CXXFLAGS) -c $< -o $@

clean:
    rm -f $(wildcard ./.o src/.o)