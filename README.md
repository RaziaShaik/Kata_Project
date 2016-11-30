# Kata_Project
Infix to RPN and from RPN to Infix converter

About Kata Project
------------------

	Kata project has been developed to create a library file that
allows conversion of mathematical expressions in the following
notations:
1. Conversion from Infix to Reverse Polish Notation (RPN) 
2. Conversion from Reverse Polish Notation (RPN) to Infix 

	Shared Object Library "libkata.so" is located in the folder 
path Kata_Project/lib

Final deliverables
------------------

libkata.so : shared object library
kata_interface.c: header file to interface the shared object library


Build procedure
---------------

To compile and build the project to generate the libkata.so, 
run the Makefile located in /Kata_Project folder

Commands to run the Makefile are below:
$make clean ----> deletes previously built files
$make   ---> compiles and builds the source kata.c in /src and kata.h 
              in /inc folder

Note: To activate print error statements present in kata.c along 
with error codes in case of errors #define PRINT 

Installing and using shared object library :
---------------------------------------------

Note : <path> is the absolute path to the /lib folder
where libkata.so file is present

Run the following commands from the terminal:

$export LD_LIBRARY_PATH=/home/..<path>../lib
$sudo ldconfig
 
Sample test procedure
----------------------

 Sample test procedure has been provided for the user to demonstrate how to
use shared object library 

To compile and build /test/test.c and to link the shared object library 
"libkata.so" and kata_interface.h file, run the Makefile placed in the 
/test folder

Run the following commands form terminal:

$ make clean ---> deletes the previously generated build files
$ make       ---> generates the executable "test" in /bin folder
$ make run   ---> to run the executable "test" present in /bin folder

sample output for Infix to RPN and RPN to Infix is printed on terminal

Check Unit Testing Framework
-----------------------------
To directly run the check test executable "check_test" present in /bin 
folder run the below command from /bin folder to generate the test report:

$./check_test

   OR

Develop test cases, build and generate the executable from scratch.
Check unit tests are located in the folder /test_check

Procedure to write and run test cases is as follows:

Step1:

-Add the test cases in the file check_kata_test.c, then follow Step2

Note:A copy of kata.c file without main function is to be placed in 
/test_check folder (Remove the main function from kata.c)

Step2:

Run the following commands from Makefile located in the /test_check folder

$ make clean ---> to delete previously generated files

$ make check  ---> generates the check test file "check_kata.c" in the same 
                              folder i.e /test_check folder

Note: In order to generate test report with complete print summary and 
one message per test(passed/failed), edit the generated "check_kata.c"
in the /test_check folder to change the following line:

FROM: srunner_run_all(sr, CK_ENV); --->  TO: srunner_run_all(sr, CK_VERBOSE);

Basically, change the CK_ENV to CK_VERBOSE in the srunner_run_all 
before going to Step3

Step3:

$ make     ---> generates the check test executable "check_kata" in the 
               folder /bin

Step4:

To run the check test executable "check_kata" located in /bin folder

$ make run ---> executes all check test cases and generates the test report
                         on the terminal

Test Coverage
--------------

A screen shot of the generated Check test coverage report has been provided in 
the folder /test_report

Rules
------

Case 1: Common to both Infix and RPN notation

- Valid operands are only lowercase letters: 'a' to 'z'. Any other character,
numbers, uppercase letters are considered invalid operands
- Valid operators are ^, /, *, -, + (Please refer to the table below
for operator precedence)

Case 2: Infix Notation

-Parenthesis () can be used to surround groups of operands and operators to 
indicate the order in which operations are performed
-Operators with equal precedence associate from left to right
For Example, a^b^c is equivalent to (a^b)^c 
-Unary operators are not considered as part of the project

Case 3: RPN Notation

- The operators follow their operands. For Example ab+
- Parenthesis () are invalid

Precedence Table:

----------------------------------------
| Precedence | Name         | Operator |
|------------|--------------|----------|
| 1          | Exponent     | ^        |
|------------|--------------|----------|    
| 2          | Division     | /        |
|------------|--------------|----------|
| 3          |Multiplication| *        |
|------------|--------------|----------|
| 4          | Subtraction  | -        |
|------------|--------------|----------|
| 5          | Addition     | +        |
---------------------------------------- 

Assumptions:
------------

- Maximum Infix or RPN input/output string length is
MAX_INPUT_STRING/MAX_OUTPUT_STRING i.e. 1024 bytes maximum


Description of Kata project
---------------------------

infixToRPN() function:

- Converts infix notation string to RPN notation
- Return is of type enum and it consists of either SUCCESS or Error codes, which specify 
the type of error (The error codes and descriptions are listed below)

RPNToInfix() function:

- Converts RPN notation string to infix notation
- Return is of type enum and it consists of either SUCCESS or Error codes, which specify
 the type of error (The error codes and descriptions are listed below)


Below are the function return error codes and descriptions:

 -SUCCESS :                    Successful conversion from Infix to RPN and vice-versa
 -FAILURE :                    Unsuccessful result (will be one of the below cases)
 -ERROR_MISMATCHED_BRACES :    When start or end parentheses are missing or are not 
                              matched properly
 -ERROR_INVALID_INPUT_EXPR :   (a) When the corresponding input expression is invalid Infix 
                              or RPN notation 
                              (b) If there are incorrect number of operators or operands 
                              (Valid expressions will always have one less number of 
                              operators than the operands) 
 -ERROR_UNDEFINED_CHARACTER :  When the input expression consists of uppercase, numbers,     
                              white spaces or any other characters except valid operators 
                              and parentheses
 -ERROR_INPUT_OUT_OF_BOUNDS :  When the input string exceeds maximum limit of 1024 or
                              if the input string is empty
 -ERROR_RPN_STORAGE_STACK_FULL:When the RPN output storage buffer exceeds Maximum of 
                              1024 bytes

Development Environment
-----------------------

-Ubuntu Linux 14.04
-GNU GCC(c99) compiler tool chain
-GNU Make
-Check (version 0.10.0) unit testing framework














