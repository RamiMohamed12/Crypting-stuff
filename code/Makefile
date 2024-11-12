# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -g

# Source files and output
SOURCES = main.cpp CaesarCipher.cpp XORCipher.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXEC = SecureCipher

# Default target: build the executable
all: $(EXEC)

# Rule to create the executable from object files
$(EXEC): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJECTS)

# Rule to compile each .cpp file into .o file
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

# Clean up the generated files
clean:
	rm -f $(OBJECTS) $(EXEC)

.PHONY: all clean

