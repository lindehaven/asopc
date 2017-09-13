@echo off

:: Calculate the start timestamp
set _time=%time%
set /a _hours=100%_time:~0,1%%%100,_min=100%_time:~3,2%%%100,_sec=100%_time:~6,2%%%100,_cs=%_time:~9,2%
set /a _started=_hours*60*60*100+_min*60*100+_sec*100+_cs

:: Beginning of test suite
set passed=0

set script=..\bin\Release\asopc.exe

set testcase="Parse correct file"
set expected=0
%script% < test_1_correct.txt >nul
if not "%errorlevel%" == "%expected%" ( echo error: Failure in %testcase%: Expected %expected% but was %errorlevel% & exit /b 1 )
set /a passed=passed+1

set testcase="Parse incorrect file: no ending semicolon"
set expected=1
%script% < test_2_incorrect.txt >nul 2>&1
if not "%errorlevel%" == "%expected%" ( echo error: Failure in %testcase%: Expected %expected% but was %errorlevel% & exit /b 1 )
set /a passed=passed+1

set testcase="Parse incorrect file: no closing parenthesis"
set expected=1
%script% < test_3_incorrect.txt >nul 2>&1
if not "%errorlevel%" == "%expected%" ( echo error: Failure in %testcase%: Expected %expected% but was %errorlevel% & exit /b 1 )
set /a passed=passed+1

set testcase="Parse incorrect file: no matching semicolon"
set expected=1
%script% < test_4_incorrect.txt >nul 2>&1
if not "%errorlevel%" == "%expected%" ( echo error: Failure in %testcase%: Expected %expected% but was %errorlevel% & exit /b 1 )
set /a passed=passed+1

set testcase="Parse incorrect file: no such keyword"
set expected=1
%script% < test_5_incorrect.txt >nul 2>&1
if not "%errorlevel%" == "%expected%" ( echo error: Failure in %testcase%: Expected %expected% but was %errorlevel% & exit /b 1 )
set /a passed=passed+1

:: End of test suite

:: Calculate the test execution time
set _time=%time%
set /a _hours=100%_time:~0,1%%%100,_min=100%_time:~3,2%%%100,_sec=100%_time:~6,2%%%100,_cs=%_time:~9,2%
set /a _duration=_hours*60*60*100+_min*60*100+_sec*100+_cs-_started
set /a _hours=_duration/60/60/100,_min=100+_duration/60/100%%60,_sec=100+(_duration/100%%60%%60),_cs=100+_duration%%100

:: Successful test suite execution
echo Success: %passed% tests passed.
echo Test time: %_hours%:%_min:~-2%:%_sec:~-2%.%_cs:~-2%
exit /b 0
