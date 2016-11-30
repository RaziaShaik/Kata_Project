/*
***********************************************************************************************
**                                	 SOURCE FILE
** Function : 1. Infix to RPN converter : Converts Infix input string to RPN output string
**                   
**            2. RPN to Infix converter : Converts RPN input string to Infix output string
**                   
** Author	:	Razia Shaik
** Date		:	11/28/2016
***********************************************************************************************
*/
#include "../inc/kata.h"

// Global variables 
uint8_t operatorArr[MAX_OPERATORS] = {'^', '/', '*', '-', '+'};

uint16_t u16ArrTop = 0;
uint16_t u16Outcount =0;
uint16_t u16OperandCount = 0;

returnType infixToRPN(char infixInput[MAX_INPUT_STRING], char rpnOut[MAX_OUTPUT_STRING])
{
	uint8_t u8Arr[MAX_ARRAY_ELEMENTS][INFIX_STACK];
	int i=0;
	uint16_t u16BraceCounter = 0;
	uint8_t precedenceCurrElem = -1;
	sint8_t s8InfixErrorCheck = 0;
	uint16_t u16InputLen = strlen(infixInput);
	charType infixCharType = NOT_DEFINED;
	//returnType returnOut = FAILURE;
	
	//initialization 
	u16ArrTop = 0;
	u16Outcount =0;
	u16OperandCount = 0;
	u8Arr[u16ArrTop][INFIX_PRECEDENCE_STACK] = MAX_PRECEDENCE;
	
	//Error Check input for boundry conditions
	if((u16InputLen >= MAX_INPUT_STRING) || (u16InputLen <= MIN_INPUT_STRING))
	{
		#ifdef PRINT
		printf("\n ERROR: Infix Input string Out of bounds, \
		                         Please provide correct Input range! \n");
		#endif //endif
		return(ERROR_INPUT_OUT_OF_BOUNDS);
	}
	
	// Read each character from the input string
	for(i=0; i < u16InputLen; i++)
	{
		infixCharType = NOT_DEFINED;
		// Function call to check the type of input character
		infixCharType = checkInputType(infixInput[i], &precedenceCurrElem);

		// Check if the character is operand from 'a' to 'z'
		if(infixCharType == OPERAND)
		{
			// store in the rpn output buffer
			rpnOut[u16Outcount++] = infixInput[i];
			// Counter to check incorrect operand position in the input
			s8InfixErrorCheck++;

		}
		// Check if the character is an operator
		else if(infixCharType == OPERATOR)
		{
			// Function call to update operator stack
			updateOperatorOut(u8Arr, infixInput[i], &precedenceCurrElem, rpnOut);	
			// Counter to check incorrect operator position in the input
			s8InfixErrorCheck--;
		}
		// Check if the character is a start brace
		else if(infixCharType == BRACE_START)
		{
			u16BraceCounter++;		
			u8Arr[u16ArrTop++][INFIX_OPERATOR_STACK] = infixInput[i];
			u8Arr[u16ArrTop][INFIX_PRECEDENCE_STACK] =  MAX_PRECEDENCE;
		}
		// Check if the character is an end brace
		else if(infixCharType == BRACE_END)
		{
			// Check for error incorrect start or end brace
			if((u16BraceCounter == ZERO) || (s8InfixErrorCheck == ZERO))
			{
				#ifdef PRINT   
				printf("\n ERROR: Infix input incorrect number of braces!\n");
				#endif // endif PRINT
				return(ERROR_MISMATCHED_BRACES);
			}
			// count the braces present and update the output
			u16BraceCounter--;

			// Update the output in case of baraces
			if(updateBraceOut(u8Arr, infixInput[i], rpnOut))
			{
				// Returns error in case of incorrect braces
				return(ERROR_MISMATCHED_BRACES);
			}
			
		}
		// Error message is printed if the input character is an undefined character
		// and also if an input character is in Uppercase
		else if(infixCharType == NOT_DEFINED)
		{
			#ifdef PRINT
			printf("\n ERROR: Infix input character not defined!\n");
			#endif // endif PRINT
			return(ERROR_UNDEFINED_CHARACTER);
		}
		// Checks for presence of incorrect operator or operand position in the infix input 
		// Also checks for the input never begins with operator
		if(s8InfixErrorCheck >= INFIX_MAX_COUNT || s8InfixErrorCheck < ZERO)
		{
			#ifdef PRINT 
			printf("\n ERROR: Infix Incorrect input; Incorrect Operator or Operand position \n");
			#endif  // endif PRINT
			return(ERROR_INVALID_INPUT_EXPR);
		}			
		
	}
	// Check for correctness of number of start and end braces
	if(u16BraceCounter > ZERO)
	{
		#ifdef PRINT 
		printf("\n ERROR: Infix input incorrect number of braces!\n");
		#endif // endif PRINT
		return(ERROR_MISMATCHED_BRACES);
	}
	// Checks for incorrect number of operators/operands
	//Number of Oparands are one more than operators in expression
	if(s8InfixErrorCheck != INPUT_ERROR_COUNT)
	{
		#ifdef PRINT 
		printf("\n ERROR: Infix Incorrect input; Incorrect number of opertors/operands \n");
		#endif //endif PRINT
		return(ERROR_INVALID_INPUT_EXPR);
	}
	// Pop out complete stack to the rpn output buffer
	while((u16ArrTop > ZERO))
	{
		rpnOut[u16Outcount++] = u8Arr[--u16ArrTop][INFIX_OPERATOR_STACK];		
	}
	rpnOut[u16Outcount] = '\0';
	
	return(SUCCESS);
}

// Function to identify whether input character is operator, operand, braces or not defined
charType checkInputType(uint8_t infixInputChar,uint8_t *precedenceCurrElem)
{
	// Initialize input chatcter to be not defined
	charType  infixCharType = NOT_DEFINED; 
	int loop=0;
	
	// Check if input character is operand 'a' to 'z' in lower case
	if(infixInputChar >= 'a' && infixInputChar <= 'z') 
	{
		infixCharType = OPERAND;
	}
	// Check if input character is start brace
	else if(infixInputChar == '(')
	{
		infixCharType = BRACE_START;
	}
	// Check if input character is end brace
	else if(infixInputChar == ')')
	{
		infixCharType = BRACE_END;
	}
	else
	{
		// Check if input character is operator
		for(loop = 0; loop < MAX_OPERATORS; loop++)
		{
			if(infixInputChar == operatorArr[loop])
			{
				infixCharType = OPERATOR;
				*precedenceCurrElem = loop;
				return infixCharType;
			}
		}		
		// if all the cases fail, then the input character which is initiazed to NOT_DEFINED is returned
		// Note: Even if the character is in Uppercase, it is considered to be NOT_DEFINED 
	}
		
	return infixCharType;	
}

// Update the output if the input character is operator
void updateOperatorOut(uint8_t u8Arr[][INFIX_STACK], uint8_t infixInput, uint8_t *precedenceCurrElem, char *rpnOut)
{
	// Check if previous operator is greater than current operator
	if(u8Arr[u16ArrTop][INFIX_PRECEDENCE_STACK] >= *precedenceCurrElem)
	{
		//push the operator to the stack 
		u8Arr[u16ArrTop++][INFIX_OPERATOR_STACK] = infixInput;

	}
	else
	{ 
		// Pop the operator stack to  output buffer till the operator precedence  
		//                           in the stack is less than current operator precedence
		while( ((u8Arr[u16ArrTop][INFIX_PRECEDENCE_STACK] < *precedenceCurrElem)) && (u16ArrTop >= ZERO))
		{	
			rpnOut[u16Outcount++] = u8Arr[--u16ArrTop][INFIX_OPERATOR_STACK];
		}
		// Push the current operator to the stack				
		u8Arr[u16ArrTop++][INFIX_OPERATOR_STACK] = infixInput;
				
	}
	// update the precedence of the operator stored in the stack
	u8Arr[u16ArrTop][INFIX_PRECEDENCE_STACK] = *precedenceCurrElem;			
	
}

//update the output with the braces
bool updateBraceOut(uint8_t u8Arr[][INFIX_STACK], uint8_t infixInput, char *rpnOut)
{
	// check if the input stack is not empty
	while( (u16ArrTop >= ZERO))
	{
		// Pop the characters stored in the stack till the start brace is found
		if (u8Arr[--u16ArrTop][INFIX_OPERATOR_STACK] == '(')
		{
			break;
		}
		// push the characters to the output buffer
		rpnOut[u16Outcount++] = u8Arr[u16ArrTop][INFIX_OPERATOR_STACK];
				
	}
	// Error check if the there are incorrect number of braces
	if(u8Arr[u16ArrTop][INFIX_OPERATOR_STACK] != '(')
	{
		#ifdef PRINT 
		printf("\n ERROR: Infix input incorrect number of braces!\n");
		#endif //endif PRINT
		return(FAILURE);
	}
	return(SUCCESS);
}


// Function to convert RPN input string to Infix output string
returnType RPNToInfix(char rpnInput[MAX_INPUT_STRING], char infixOut[MAX_OUTPUT_STRING])
{
	uint8_t u8ArrOperand[MAX_ARRAY_ELEMENTS][RPN_EXPRESSION_SIZE];
	int i=0;
	charType rpnCharType = NOT_DEFINED;
	sint8_t s8RPNErrorCheck = 0;
	uint8_t precedenceCurrElem = -1;
	uint16_t u16InputLen = strlen(rpnInput);
	
	//initialize
	u16OperandCount = 0;
   
    //Error Check input for boundary conditions
    if((u16InputLen >= MAX_INPUT_STRING) || (u16InputLen <= MIN_INPUT_STRING))
	{
		#ifdef PRINT 
		printf("\n ERROR: RPN Input string Out of bounds, \
		                          Please provide correct Input range! \n");
		#endif // endif PRINT
		return(ERROR_INPUT_OUT_OF_BOUNDS);
	}
	
	// Read each character from the input string
	for(i=0; i < u16InputLen; i++)
	{
		rpnCharType = NOT_DEFINED;
		rpnCharType = checkInputType(rpnInput[i], &precedenceCurrElem);
		
		//check if input is operand
		if(rpnCharType == OPERAND)
		{
			//push operands to array u8ArrOperand and operands are stored as strings
			*(u8ArrOperand[u16OperandCount]) = rpnInput[i];	
			u8ArrOperand[u16OperandCount][1] = '\0';
			u16OperandCount++;
			// Counter to check incorrect operand number in the input
			s8RPNErrorCheck++;
		}
		// check if the input is operator
		else if(rpnCharType == OPERATOR)
		{
			// Check for correct number of operands present in stack 
			if(u16OperandCount < RPN_NUM_OPERANDS)
			{
				#ifdef PRINT 
				printf("\n ERROR: RPN Incorrect input, Please provide correct Input!\n");
				#endif // endif PRINT
				return(ERROR_INVALID_INPUT_EXPR);
			}
			// Update the Infix output by popping out top elements from the operand stack array
			if(updateOperatorInfixOut(u8ArrOperand,rpnInput[i],precedenceCurrElem))
			{
				return(ERROR_RPN_STORAGE_STACK_FULL);
			}
			// Counter to check incorrect operand number in the input
			s8RPNErrorCheck--;
		
		}
		// Error checking if the input is not operator or operand, then prints the error message
		// Uppercase operands are also considered to be incorrect input
		else if(rpnCharType == NOT_DEFINED || rpnCharType == BRACE_START || rpnCharType == BRACE_END)
		{
			#ifdef PRINT 
			printf("\n ERROR: RPN Character not defined, Please provide correct Input!\n");
			#endif //endif PRINT
			return(ERROR_UNDEFINED_CHARACTER);
		}
	}	
	// Checks for incorrect number of operators/operands
	//Number of Oparands are one more than operators in expression
	if(s8RPNErrorCheck != INPUT_ERROR_COUNT)
	{
		#ifdef PRINT 
		printf("\n ERROR: RPN Incorrect input, Incorrect number of operators or operands!\n");
		#endif // endif PRINT
		return(ERROR_INVALID_INPUT_EXPR);
	}
	// Copy the expression stored in stack to the output array
	strcpy(infixOut,(const char*)u8ArrOperand[--u16OperandCount]);

	return (SUCCESS);

}

bool updateOperatorInfixOut(uint8_t u8ArrOperand[][RPN_EXPRESSION_SIZE],uint8_t rpnInput, uint8_t precedenceCurrElem)
{
	char right[MAX_ARRAY_ELEMENTS] ;
	char left[MAX_ARRAY_ELEMENTS];
	char strBrace[MAX_ARRAY_ELEMENTS];
	char operator[RPN_ELEMENT_SIZE];
	
	// Copy top two  expression array elements to the left and right variables
	strcpy(left,(const char*)(u8ArrOperand[--u16OperandCount]));
	strcpy(right, (const char*)(u8ArrOperand[--u16OperandCount]));
			
	// Convert the operator to string format		
	operator[0] = operatorArr[precedenceCurrElem];
	operator[1] = '\0';
	
	// Add braces to the right expression		
	if(strlen(right) != RPN_OPERAND_LEN)
	{
		strBrace[0] = '(';
		strcpy(strBrace+1, right);
		strcpy(strBrace+strlen(strBrace),")");
		strcpy(right,strBrace);
	}
	// Add braces to the left expression			
	if(strlen(left) != RPN_OPERAND_LEN)
	{
		strBrace[0] = '(';
		strcpy(strBrace+1, left);
		strcpy(strBrace+strlen(strBrace),")");
		strcpy(left, strBrace);
	}		
	// Concatenate right + operator + left expression 
	strcat(right, operator);
	strcat(right,left);
	
	// Check if the intermediate expression to be stored is within memory bounds 
	if( strlen(right) < RPN_EXPRESSION_SIZE)
	{
		// Store expression in the array u8ArrOperand
		strcpy((char*)(u8ArrOperand[u16OperandCount++]), right);
	}
	else
	{
		#ifdef PRINT 
		printf("\n ERROR: RPN Expression storage length out of range!\n");
		#endif //endif PRINT
		return(FAILURE);
	}
	return(SUCCESS);
}



