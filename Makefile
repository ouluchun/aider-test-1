#Simple Makefile for hello_world.cpp
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11
TARGET = hello_world

all: $(TARGET)

$(TARGET): hello_world.cpp
	$(CXX) $(CXXFLAGS) -o $(TARGET) hello_world.cpp

clean:
	rm -f $(TARGET)

.PHONY: all clean
