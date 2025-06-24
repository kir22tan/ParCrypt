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
       $(OBJ_DIR)/env_loader.o \
       $(OBJ_DIR)/main.o

# Executable
TARGET = ParCrypt

# Default rule
all: create_obj_dir $(TARGET)

# Create the objects directory if it doesn't exist
create_obj_dir:
	@if not exist $(OBJ_DIR) mkdir $(OBJ_DIR)

# Link object files into final executable
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

# Compile main.cpp separately
$(OBJ_DIR)/main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile all src/ cpp files into objects/
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build artifacts
clean:
	@if exist $(OBJ_DIR) rmdir /s /q $(OBJ_DIR)
	@if exist $(TARGET).exe del $(TARGET).exe
