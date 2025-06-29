# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++23 -Wall -Iinclude

# Directories
SRC_DIR = src
OBJ_DIR = obj

# Object files
OBJS = $(OBJ_DIR)/file_manager.o \
       $(OBJ_DIR)/thread_manager.o \
       $(OBJ_DIR)/encryptor.o

# Executable
TARGET = ParCrypt

# Default rule
all: create_obj_dir $(TARGET)

create_obj_dir:
	@if not exist $(OBJ_DIR) mkdir $(OBJ_DIR)

# Link object files with main
$(TARGET): $(OBJS) main.cpp
	$(CXX) $(CXXFLAGS) main.cpp $(OBJS) -o $(TARGET)

# Compile source files to object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build artifacts
clean:
	@if exist $(OBJ_DIR) rmdir /s /q $(OBJ_DIR)
	@if exist $(TARGET).exe del $(TARGET).exe
