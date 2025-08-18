#!/bin/bash
set -e

echo "Running tests for Replacer."

# Test 1: Basic replacement
echo "hello world" > file1.txt
./ex04 file1.txt hello hi
diff <(cat file1.txt.replace) <(echo "hi world") || { echo "Test 1 failed"; exit 1; }

# Test 2: Multiple occurrences
echo "aaa bbb aaa ccc aaa" > file2.txt
./ex04 file2.txt aaa xxx
diff <(cat file2.txt.replace) <(echo "xxx bbb xxx ccc xxx") || { echo "Test 2 failed"; exit 1; }

# Test 3: No occurrence
echo "test string" > file3.txt
./ex04 file3.txt foo bar
diff <(cat file3.txt.replace) <(echo "test string") || { echo "Test 3 failed"; exit 1; }

# Test 4: Empty s1 (should fail)
if ./ex04 file3.txt "" bar 2>/dev/null; then
  echo "Test 4 failed: program should exit with error on empty s1"
  exit 1
fi

# Test 5: Empty s2 (delete occurrences)
echo "remove remove keep" > file5.txt
./ex04 file5.txt remove ""
diff <(cat file5.txt.replace) <(echo "  keep") || { echo "Test 5 failed"; exit 1; }

# Test 6: s1 == s2 (no change)
echo "unchanged unchanged" > file6.txt
./ex04 file6.txt unchanged unchanged
diff file6.txt file6.txt.replace || { echo "Test 6 failed"; exit 1; }

# Test 7: s1 longer than content
echo "short" > file7.txt
./ex04 file7.txt "muchlongerpattern" XXX
diff file7.txt file7.txt.replace || { echo "Test 7 failed"; exit 1; }

# Test 8: Very large file (strict check)
yes "data data" | head -n 100000 > file8.txt
./ex04 file8.txt data info
yes "info info" | head -n 100000 > expected8.txt
diff file8.txt.replace expected8.txt || { echo "Test 8 failed"; exit 1; }

# Test 9: Special characters
echo "a+b=c? a+b=c?" > file9.txt
./ex04 file9.txt "a+b" "sum"
diff <(cat file9.txt.replace) <(echo "sum=c? sum=c?") || { echo "Test 9 failed"; exit 1; }

# Test 10: File with no newlines
echo -n "aaa bbb aaa ccc" > file10.txt  # -n avoids adding a newline
./ex04 file10.txt aaa xxx
diff <(cat file10.txt.replace) <(echo -n "xxx bbb xxx ccc") || { echo "Test 10 failed"; exit 1; }

# Test 11: File with multiple consecutive newlines
printf "line1\n\n\nline2\n\nline3\n" > file11.txt
./ex04 file11.txt line lineX
diff <(cat file11.txt.replace) <(printf "lineX1\n\n\nlineX2\n\nlineX3\n") || { echo "Test 11 failed"; exit 1; }

# Test 12: File with only newlines
printf "\n\n\n" > file12.txt
./ex04 file12.txt anything something
diff file12.txt.replace file12.txt || { echo "Test 12 failed"; exit 1; }

echo "All tests passed"
