# Compiler and flags
CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -O2

# Source files
CPP_SOURCES := hello_world.cpp test_greeting.cpp

# Executable names (derived from source filenames)
EXECUTABLES := $(CPP_SOURCES:.cpp=)

# Default target
all: $(EXECUTABLES)

# Pattern rule to build each executable from its.cpp file
%: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

# Clean up generated files
clean:
	rm -f $(EXECUTABLES)

.PHONY: all clean
