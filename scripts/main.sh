#!/bin/bash

# NEED THE FOLLOWING FILE STRUCTURE FOR SCRIPT TO RUN
# - input/
#     - Feature (e.g., create, delete, etc.)
#         - in/   (input files)
#         - out/  (expected terminal output)
#         - eout/ (expected transaction output)
# - output/
#     - text/ (terminal outputs from running program)
#     - file/ (transaction outputs from running program)
# - Reports/
#     - Test-Summary-<timestamp>.txt (summary of test results)

# Set paths
INPUT_DIR="./input"
OUTPUT_DIR="./scripts/output"
TEXT_OUTPUT_DIR="$OUTPUT_DIR/text"
FILE_OUTPUT_DIR="$OUTPUT_DIR/file"
REPORTS_DIR="./scripts/Reports"
BANKING_SYSTEM="./bin/banking_system"

# Create necessary directories if not present
mkdir -p "$TEXT_OUTPUT_DIR" "$FILE_OUTPUT_DIR" "$REPORTS_DIR"

# Ensures the project can be cleaned before rebuilding
clean:
    rm -rf bin/*.o bin/banking_system

# Build the project
echo "Building the project..."
cd src || exit
make clean && make -f ../Makefile
cd .. || exit

# Create summary report file
SUMMARY_FILE="$REPORTS_DIR/Test-Summary-$(date +'%m-%d-%Y-%H-%M-%S').txt"
echo "Errors:" > "$SUMMARY_FILE"

# Run tests
echo "Running Tests..."
for FEATURE in "$INPUT_DIR"/*; do
    if [ -d "$FEATURE" ]; then
        FEATURE_NAME=$(basename "$FEATURE")
        echo "Testing feature: $FEATURE_NAME"

        # Iterate over input files for the feature
        for INPUT_FILE in "$FEATURE/in/"*; do
            if [ -f "$INPUT_FILE" ]; then
                TEST_NAME=$(basename "$INPUT_FILE" .in)
                echo "Running test: $TEST_NAME"

                # Generate terminal output
                TERMINAL_OUTPUT="$TEXT_OUTPUT_DIR/$TEST_NAME.out"
                $BIN_PATH < "$INPUT_FILE" > "$TERMINAL_OUTPUT"
            fi
        done
        echo "DONE Testing $FEATURE_NAME"
        echo
    fi
done

# Compare actual outputs to expected outputs
echo "Comparing Outputs..."
echo "Terminal Errors below:" >> "$SUMMARY_FILE"
for FEATURE in "$INPUT_DIR"/*; do
    if [ -d "$FEATURE" ]; then
        FEATURE_NAME=$(basename "$FEATURE")
        echo "Comparing outputs for feature: $FEATURE_NAME"

        # Compare terminal outputs
        for EXPECTED_OUTPUT in "$FEATURE/out/"*; do
            if [ -f "$EXPECTED_OUTPUT" ]; then
                TEST_NAME=$(basename "$EXPECTED_OUTPUT" .out)
                ACTUAL_OUTPUT="$TEXT_OUTPUT_DIR/$TEST_NAME.out"

                if diff -q "$EXPECTED_OUTPUT" "$ACTUAL_OUTPUT" > /dev/null; then
                    echo "Test $TEST_NAME PASSED"
                else
                    echo "Test $TEST_NAME FAILED"
                    echo "Test: $TEST_NAME -- FAIL" >> "$SUMMARY_FILE"
                fi
            fi
        done
    fi
done

echo "Testing completed. Check $SUMMARY_FILE for a summary of results."