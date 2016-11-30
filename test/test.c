/*
***********************************************************************************************
**                                		TEST SOURCE FILE
** Function : main function to test
* *           1. Infix to RPN converter : Converts Infix input string to RPN output string                  
**            2. RPN to Infix converter : Converts RPN input string to Infix output string
**                   
** Author	:	Razia Shaik
** Date		:	11/28/2016
***********************************************************************************************
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include "../inc/kata_interface.h"

int main(int argc, char *argv[])
{
	// variables for Infix 
	char arInfix[MAX_INPUT_STRING]= "((v/w)^x)*(y-z)";
	char outRpn[MAX_INPUT_STRING];
	
	// Variables for RPN
	char arRpn[MAX_INPUT_STRING] = "ag+ba-c+cedf^*+^*";
	char outInfix[MAX_OUTPUT_STRING];
	returnType out = FAILURE;

	// Converts Infix input to RPN output
	out = infixToRPN(arInfix, outRpn);
	
	if(out == SUCCESS)
	{
		printf("\n Infix Input  = %s \n RPN Output   = %s \n", arInfix, outRpn);
	}
	else
	{
		printf("\nERROR CODE = %d\n", out);
	}

	//Converts RPN input to Infix output
	out = RPNToInfix(arRpn, outInfix);	
	if(out == SUCCESS)
	{
		printf("\n RPN Input    = %s \n Infix Output = %s \n\n",arRpn, outInfix);
	}
	else
	{
		printf("\nERROR CODE = %d\n", out);
	}

	return 0;
}

