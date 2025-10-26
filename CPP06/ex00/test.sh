#!/bin/bash

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

echo "================================"
echo "ScalarConverter Comprehensive Tests"
echo "================================"
echo ""

# Test function
run_test() {
    echo -e "${YELLOW}Testing: $1${NC}"
    ./ex00 "$1"
    echo "--------------------------------"
    echo ""
}

# Character tests
echo -e "${GREEN}=== CHARACTER TESTS ===${NC}"
run_test "a"
run_test "z"
run_test "A"
run_test "Z"
run_test "0"
run_test "9"
run_test "!"
run_test "@"

# Integer tests
echo -e "${GREEN}=== INTEGER TESTS ===${NC}"
run_test "0"
run_test "42"
run_test "-42"
run_test "+42"
run_test "2147483647"   # INT_MAX
run_test "-2147483648"  # INT_MIN
run_test "2147483648"   # INT_MAX + 1 (should be impossible for int)

# Float tests
echo -e "${GREEN}=== FLOAT TESTS ===${NC}"
run_test "0.0f"
run_test "42.0f"
run_test "-42.0f"
run_test "+42.0f"
run_test "42.42f"
run_test "-42.42f"
run_test "0.1f"
run_test "123.456f"
run_test "-inff"
run_test "+inff"
run_test "nanf"

# Double tests
echo -e "${GREEN}=== DOUBLE TESTS ===${NC}"
run_test "0.0"
run_test "42.0"
run_test "-42.0"
run_test "+42.0"
run_test "42.42"
run_test "-42.42"
run_test "0.1"
run_test "123.456"
run_test "-inf"
run_test "+inf"
run_test "nan"

# Edge cases
echo -e "${GREEN}=== EDGE CASES ===${NC}"
run_test "127"    # Max char
run_test "128"    # Beyond max char
run_test "-1"     # Negative char
run_test "255"    # Upper char boundary
run_test "256"    # Beyond char range

# Non-printable characters
echo -e "${GREEN}=== NON-PRINTABLE TESTS ===${NC}"
run_test "0"      # NULL char
run_test "31"     # Non-printable
run_test "32"     # Space (first printable)
run_test "126"    # ~ (last printable)
run_test "127"    # DEL (non-printable)

# Invalid inputs
echo -e "${GREEN}=== INVALID INPUT TESTS ===${NC}"
run_test "abc"
run_test "12.34.56"
run_test "42f"     # Missing decimal point
run_test "42.f"    # Missing digit after dot
run_test ".42f"    # Missing digit before dot
run_test "42."     # Missing digit after dot (double)
run_test ".42"     # Missing digit before dot (double)
run_test "++42"
run_test "--42"
run_test "42-"
run_test ""        # Empty string
run_test "inf"     # Missing sign
run_test "inff"    # Missing sign
run_test "42 "     # Space
run_test " 42"     # Space

# Precision tests
echo -e "${GREEN}=== PRECISION TESTS ===${NC}"
run_test "42.123456789f"
run_test "42.123456789"

echo -e "${GREEN}=== ALL TESTS COMPLETED ===${NC}"
