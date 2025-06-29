# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++23 -Wall -Iinclude

# Directories
SRC_DIR = src
OBJ_DIR = obj

# Object files
OBJS = $(OBJ_DIR)/file_manager.o \
       $(OBJ_DIR)/thread_manager.o \
       $(OBJ_DIR)/encryptor.o \
       $(OBJ_DIR)/main.o

# Executable name
TARGET = ParCrypt.exe

# Default target
all: create_obj_dir $(TARGET)

# Create obj dir if not exists (Windows syntax)
create_obj_dir:
	@if not exist $(OBJ_DIR) mkdir $(OBJ_DIR)

# Link all object files
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

# Compile main.cpp
$(OBJ_DIR)/main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile src/*.cpp files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean everything
clean:
	@if exist $(OBJ_DIR) rmdir /s /q $(OBJ_DIR)
	@if exist $(TARGET) del $(TARGET)
