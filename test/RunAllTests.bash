#!/usr/bin/env bash

# :: Calculate the start timestamp
start=$(date +%s.%N)

# :: Beginning of test suite
passed=0
script="../bin/Release/asopc.exe"

testcase="Parse correct file"
expected=0
$script < test_1_correct.txt >/dev/null
result=$?
if [ $result != $expected ]; then echo error: Failure in $testcase: Expected $expected but was $result; exit 1; fi
((passed++))

testcase="Parse incorrect file: no ending semicolon"
expected=1
$script < test_2_incorrect.txt >/dev/null 2>&1
result=$?
if [ $result != $expected ]; then echo error: Failure in $testcase: Expected $expected but was $result; exit 1; fi
((passed++))

testcase="Parse incorrect file: no closing parenthesis"
expected=1
$script < test_3_incorrect.txt >/dev/null 2>&1
result=$?
if [ $result != $expected ]; then echo error: Failure in $testcase: Expected $expected but was $result; exit 1; fi
((passed++))

testcase="Parse incorrect file: no matching semicolon"
expected=1
$script < test_4_incorrect.txt >/dev/null 2>&1
result=$?
if [ $result != $expected ]; then echo error: Failure in $testcase: Expected $expected but was $result; exit 1; fi
((passed++))

testcase="Parse incorrect file: no such keyword"
expected=1
$script < test_5_incorrect.txt >/dev/null 2>&1
result=$?
if [ $result != $expected ]; then echo error: Failure in $testcase: Expected $expected but was $result; exit 1; fi
((passed++))
# :: End of test suite

# :: Calculate the test execution time
end=$(date +%s.%N)    
duration=`echo "$start" "$end" | awk '{printf "%f\n", $2-$1}'`
hh=`echo "$duration" | awk '{printf "%d\n", $1/3600}'`
mm=`echo "$duration" | awk '{printf "%02d\n", $1/60%60}'`
ss=`echo "$duration" | awk '{printf "%02d\n", $1%60%60}'`
ms=`echo "$duration" | awk '{printf "%02d\n", ($1+0.005)*100%100}'`

# :: Successful test suite execution
echo Success: $passed tests passed.
echo Test time: $hh:$mm:$ss.$ms

exit 0
