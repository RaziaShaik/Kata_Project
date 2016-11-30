/*
***********************************************************************************************
**                                		HEADER FILE
** Function : 1. Infix to RPN converter : Converts Infix input string to RPN output string
**                   
**            2. RPN to Infix converter : Converts RPN input string to Infix output string
**                   
** Author	:	Razia Shaik
** Date		:	11/28/2016
***********************************************************************************************
*/

#ifndef _KATA_H_
#define _KATA_H_

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

typedef unsigned int uint32_t;
typedef unsigned short uint16_t;
typedef unsigned char uint8_t;
typedef signed int sint8_t;

// To activate print error statement in kata.c define PRINT
//#define PRINT

#define MAX_ARRAY_ELEMENTS              1024    // Maximum stack size to store operators
#define MAX_PRECEDENCE_ELEMENTS         1024	// Maximum stack size to store precedence

#define MAX_OPERATORS                   5		// Maximum number of operators
#define RPN_EXPRESSION_SIZE             1024	// Max RPN expression size

#define INFIX_STACK                     2       // Stack storing operator and precedence 
#define INFIX_OPERATOR_STACK            0		// Infix operator stack
#define INFIX_PRECEDENCE_STACK          1		// Infix precedence stack

#define INFIX_MAX_COUNT                 2		// Error count for continuous operators or operands

#define MAX_INPUT_STRING                1024	// Maximum input string length
#define MIN_INPUT_STRING                0		// Minimum input string length
#define MAX_OUTPUT_STRING               1024	// Maximum output string length
#define MAX_PRECEDENCE                  6		// Maximum precedence set
#define INPUT_ERROR_COUNT               1		// Error check for correct operator/operand number

#define ZERO                            0		// Check for Empty stack

#define RPN_NUM_OPERANDS                2		// Number of RPN operands in stack
#define RPN_OPERAND_LEN                 1		// Length of RPN operand 
#define RPN_EXPRESSION_SIZE             1024	// Length of RPN expression storage size
#define RPN_ELEMENT_SIZE                2		// RPN element size

// enum to check operators, operands, braces and undefined input character
typedef enum{ OPERATOR, OPERAND, BRACE_START, BRACE_END, NOT_DEFINED} charType;

// Returns Error status enum
/*
 * SUCCESS: Return successful conversion
 * FAILURE: Return on Failure conversion
 * ERROR_MISMATCHED_BRACES: Returns for incorrect number of braces or mismatched braces
 * ERROR_INVALID_INPUT_EXPR: Returns on invalid input epression
 * ERROR_UNDEFINED_CHARACTER: Returns on Uppercase, Numbers or Undefined Characters
 * ERROR_INPUT_OUT_OF_BOUNDS: Return on input max and min stack range is out of bounds
 * ERROR_RPN_STORAGE_STACK_FULL: Return on the output storage stack is full
 * */
typedef enum{ SUCCESS,\
	          FAILURE,\
	          ERROR_MISMATCHED_BRACES,\
	          ERROR_INVALID_INPUT_EXPR,\
	          ERROR_UNDEFINED_CHARACTER,\
	          ERROR_INPUT_OUT_OF_BOUNDS,\
	          ERROR_RPN_STORAGE_STACK_FULL\
	         } returnType;

// Infix to RPN conversion  external function 
extern returnType infixToRPN(char infixInput[MAX_INPUT_STRING], char rpnOut[MAX_OUTPUT_STRING]);
// RPN to Infix conversion external function
extern returnType RPNToInfix(char rpnInput[MAX_INPUT_STRING], char infixOut[MAX_OUTPUT_STRING]);

// Functions to check the character type  
charType checkInputType(uint8_t, uint8_t* );
// Functions to update the output if the infix input character is operator
void updateOperatorOut(uint8_t u8Arr[][INFIX_STACK], uint8_t , uint8_t*, char*);
// Functions to update the output if the infix input character is brace
bool updateBraceOut(uint8_t u8Arr[][INFIX_STACK], uint8_t, char*);
// Functions to update the output if the input character is operator and result is infix output
bool updateOperatorInfixOut(uint8_t u8ArrOperand[][RPN_EXPRESSION_SIZE],uint8_t ,uint8_t);

#endif //endif _KATA_H_
