#!/bin/bash

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

# Counters
TOTAL=0
PASSED=0
FAILED=0

# Program name
PROGRAM="./RPN"

# Check if program exists
if [ ! -f "$PROGRAM" ]; then
    echo -e "${RED}Error: $PROGRAM not found!${NC}"
    echo "Please compile the program first."
    exit 1
fi

echo "=========================================="
echo "    RPN Calculator Test Suite"
echo "=========================================="
echo ""

# Function to run a test
run_test() {
    local test_name="$1"
    local input="$2"
    local expected="$3"
    local should_fail="$4"
    
    TOTAL=$((TOTAL + 1))
    
    echo -n "Test $TOTAL: $test_name ... "
    
    # Run the program and capture output
    output=$($PROGRAM "$input" 2>&1)
    exit_code=$?
    
    if [ "$should_fail" = "fail" ]; then
        # Test should produce an error
        if [ $exit_code -ne 0 ] || [[ "$output" == *"Error"* ]]; then
            echo -e "${GREEN}PASS${NC}"
            PASSED=$((PASSED + 1))
        else
            echo -e "${RED}FAIL${NC}"
            echo "  Expected: Error"
            echo "  Got: $output"
            FAILED=$((FAILED + 1))
        fi
    else
        # Test should succeed with expected output
        if [ "$output" = "$expected" ]; then
            echo -e "${GREEN}PASS${NC}"
            PASSED=$((PASSED + 1))
        else
            echo -e "${RED}FAIL${NC}"
            echo "  Input: $input"
            echo "  Expected: $expected"
            echo "  Got: $output"
            FAILED=$((FAILED + 1))
        fi
    fi
}

echo "--- Basic Operations ---"
run_test "Simple addition" "1 2 +" "3"
run_test "Simple subtraction" "5 3 -" "2"
run_test "Simple multiplication" "4 2 *" "8"
run_test "Simple division" "8 2 /" "4"

echo ""
echo "--- Complex Expressions ---"
run_test "Subject example 1" "8 9 * 9 - 9 - 9 - 4 - 1 +" "42"
run_test "Subject example 2" "7 7 * 7 -" "42"
run_test "Subject example 3" "1 2 * 2 / 2 * 2 4 - +" "0"
run_test "Multiple operations" "3 4 + 2 * 7 /" "2"
run_test "Negative result" "3 5 -" "-2"
run_test "Complex calculation" "9 5 1 1 + - / 3 * 2 1 1 + + -" "5"

echo ""
echo "--- Single Number ---"
run_test "Single digit" "9" "9"
run_test "Just zero" "0" "0"

echo ""
echo "--- Edge Cases ---"
run_test "Division by zero" "5 0 /" "Error" "fail"
run_test "Large numbers combined" "9 9 * 9 9 * +" "162"
run_test "All operations" "5 1 2 + 4 * + 3 -" "14"

echo ""
echo "--- Error Cases ---"
run_test "Empty argument" "" "Error" "fail"
run_test "No operators" "1 2 3" "Error" "fail"
run_test "Too many operators" "1 + +" "Error" "fail"
run_test "Invalid character" "1 2 a" "Error" "fail"
run_test "Number > 9" "10 2 +" "Error" "fail"
run_test "Double digit" "12 2 +" "Error" "fail"
run_test "Operator first" "+ 1 2" "Error" "fail"
run_test "Not enough operands" "1 2 + +" "Error" "fail"
run_test "Floating point" "1.5 2 +" "Error" "fail"
run_test "Negative number input" "-1 2 +" "Error" "fail"

echo ""
echo "--- No Arguments ---"
run_test "No arguments" "" "Error" "fail"

echo ""
echo "=========================================="
echo "           Test Summary"
echo "=========================================="
echo -e "Total tests: ${YELLOW}$TOTAL${NC}"
echo -e "Passed: ${GREEN}$PASSED${NC}"
echo -e "Failed: ${RED}$FAILED${NC}"
echo ""

if [ $FAILED -eq 0 ]; then
    echo -e "${GREEN}All tests passed! ✓${NC}"
    exit 0
else
    echo -e "${RED}Some tests failed! ✗${NC}"
    exit 1
fi