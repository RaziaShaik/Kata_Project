/*
***********************************************************************************************
**                                		INTERFACE INCLUDE FILE
** Function : Interface header file to call the following functions from shared object 
**           library "libkata.so" file present in the /lib directory
**           1. Infix to RPN converter : Converts the Infix input string to RPN output string                  
**           2. RPN to Infix converter : Converts the RPN input string to Infix output string
**                   
** Author	:	Razia Shaik
** Date		:	11/28/2016
***********************************************************************************************
*/

#include <stdbool.h>

#ifndef _KATA_INTERFACE_H_
#define _KATA_INTERFACE_H_

#define MAX_INPUT_STRING	1024	// Maximum input string length
#define MAX_OUTPUT_STRING	1024	// Maximum output string length

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
	         
// Infix to RPN conversion external function
extern returnType infixToRPN(char infixInput[MAX_INPUT_STRING], char rpnOut[MAX_OUTPUT_STRING]);
// RPN to Infix conversion external function
extern returnType RPNToInfix(char rpnInput[MAX_INPUT_STRING], char infixOut[MAX_OUTPUT_STRING]);

#endif // _KATA_INTERFACE_H_
