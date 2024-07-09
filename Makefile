# Variables
CC = g++      # Compiler
CFLAGS = -Wall -g   # Compiler flags
TARGET = tactactoe    # Target executable name

# Default target (the one that gets built if no arguments are given)
all: $(TARGET)

# Rule for building the target
$(TARGET): main.cpp
	$(CC) $(CFLAGS) -o $(TARGET) main.cpp

# Clean rule to remove the target
clean:
	rm -f $(TARGET)
