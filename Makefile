# Compiler and flags
CXX = clang++
CXXFLAGS = -std=c++17 -Wall -Wextra -I./src

# Directories
SRC_DIR = ./src
BIN_DIR = ./bin
DATA_DIR = ./data
TEST_DIR = ./tests
INPUT_DIR = ./input

# Source and object files
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(SOURCES:$(SRC_DIR)/%.cpp=$(BIN_DIR)/%.o)
TARGET = $(BIN_DIR)/banking_system

# Default target
all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean generated files
clean:
	rm -rf $(BIN_DIR)/* $(INPUT_DIR)/*/eout/*.eout

# Test the program
test: $(TARGET)
	@echo "Running tests..."
	@for dir in $(INPUT_DIR)/*; do \
	    if [ -d $$dir ]; then \
	        for input in $$dir/in/*; do \
	            operation=$$(basename $$dir); \
	            base_name=$$(basename $$input .in); \
	            expected=$$dir/out/$$base_name.out; \
	            actual=$$dir/eout/$$base_name.eout; \
	            echo "Testing $$operation with $$input..."; \
	            ./$(TARGET) < $$input > $$actual; \
	            if diff -q $$expected $$actual; then \
	                echo "Test $$operation/$$base_name PASSED"; \
	            else \
	                echo "Test $$operation/$$base_name FAILED"; \
	            fi; \
	        done; \
	    fi \
	done
	@echo "Testing completed."