
#include "../inc/kata.h"

#test infix_Input1
	char rpnOut[MAX_OUTPUT_STRING];
	returnType out = infixToRPN("a+b-c",rpnOut);

	ck_assert_int_eq(out,SUCCESS);

	if(out == SUCCESS)
	{
		ck_assert_str_eq(rpnOut, "abc-+");
	}

#test infix_Input2
	char rpnOut[MAX_OUTPUT_STRING];
	returnType out = infixToRPN("(a+b)-c",rpnOut);

	ck_assert_int_eq(out,SUCCESS);

	if(out == SUCCESS)
	{
		ck_assert_str_eq(rpnOut, "ab+c-");
	}

#test infix_Input3
	char rpnOut[MAX_OUTPUT_STRING];
	returnType out = infixToRPN("((l/(m^n))*o)-p",rpnOut);

	ck_assert_int_eq(out,SUCCESS);

	if(out == SUCCESS)
	{
		ck_assert_str_eq(rpnOut, "lmn^/o*p-");
	}

#test infix_Input4
	char rpnOut[MAX_OUTPUT_STRING];
	returnType out = infixToRPN("((v/w)^x)*(y-z)",rpnOut);

	ck_assert_int_eq(out,SUCCESS);

	if(out == SUCCESS)
	{
		ck_assert_str_eq(rpnOut, "vw/x^yz-*");
	}

#test infix_input5
	char rpnOut[MAX_OUTPUT_STRING];
	returnType out = infixToRPN("(a+g)*(((b-a)+c)^(c+(e*(d^f))))",rpnOut);

	ck_assert_int_eq(out,SUCCESS);

	if(out == SUCCESS)
	{
		ck_assert_str_eq(rpnOut, "ag+ba-c+cedf^*+^*");
	}

#test infix_Boundry_Limit_Check
	char rpnOut[MAX_OUTPUT_STRING];
	// check input is null
	returnType out = infixToRPN("",rpnOut);

	ck_assert_int_eq(out,ERROR_INPUT_OUT_OF_BOUNDS);

	if(out == SUCCESS)
	{
		ck_assert_str_eq(rpnOut, "");
	}

#test infix_Extra_Start_Brace_Check
	char rpnOut[MAX_OUTPUT_STRING];
	returnType out = infixToRPN("b/(f*e-f+(z-y)*k/m",rpnOut);
	
	ck_assert_int_eq(out,ERROR_MISMATCHED_BRACES);

	if(out == SUCCESS)
	{
		ck_assert_str_eq(rpnOut, "");
	}

#test infix_Extra_End_Brace_Check
	char rpnOut[MAX_OUTPUT_STRING];
	returnType out = infixToRPN("b/f*e-f+(z-y)*k/m)",rpnOut);
	
	ck_assert_int_eq(out,ERROR_MISMATCHED_BRACES);

	if(out == SUCCESS)
	{
		ck_assert_str_eq(rpnOut, "");
	}

#test infix_Incorrect_Brace_Check
	char rpnOut[MAX_OUTPUT_STRING];
	returnType out = infixToRPN("b/(f*e-f+(z-)y)*k/m",rpnOut);
	
	ck_assert_int_eq(out,ERROR_MISMATCHED_BRACES);

	if(out == SUCCESS)
	{
		ck_assert_str_eq(rpnOut, "");
	}

#test infix_Missing_Operator_Check
	char rpnOut[MAX_OUTPUT_STRING];
	// check missing operator between a and b and c
	returnType out = infixToRPN("abc+g-f/e-z+y",rpnOut);
	
	ck_assert_int_eq(out,ERROR_INVALID_INPUT_EXPR);

	if(out == SUCCESS)
	{
		ck_assert_str_eq(rpnOut, "");
	}

#test infix_Extra_Operator_Check
	char rpnOut[MAX_OUTPUT_STRING];
	// extra operator - at the end
	returnType out = infixToRPN("a*b-f+(g-h+q)/n+p-",rpnOut);
	
	ck_assert_int_eq(out,ERROR_INVALID_INPUT_EXPR);

	if(out == SUCCESS)
	{
		ck_assert_str_eq(rpnOut, "");
	}


#test infix_Uppercase_Operand_Check
	char rpnOut[MAX_OUTPUT_STRING];
        // Uppercase letters are undefined characters, as only only lowercase letters are valid
	returnType out = infixToRPN("a-b+q/M*n",rpnOut);
	
	ck_assert_int_eq(out,ERROR_UNDEFINED_CHARACTER);

	if(out == SUCCESS)
	{
		ck_assert_str_eq(rpnOut, "");
	}


#test infix_Undefined_Operand_Check
	char rpnOut[MAX_OUTPUT_STRING];
	// undefined character & is present in the input
	returnType out = infixToRPN("vw&x^yz-*",rpnOut);
	
	ck_assert_int_eq(out,ERROR_INVALID_INPUT_EXPR);

	if(out == SUCCESS)
	{
		ck_assert_str_eq(rpnOut, "");
	}

#test infix_White_Space_Character_Check
	char rpnOut[MAX_OUTPUT_STRING];
	// White spaces are considered as undefined character 
	returnType out = infixToRPN("a + b-c",rpnOut);
	
	ck_assert_int_eq(out,ERROR_UNDEFINED_CHARACTER);

	if(out == SUCCESS)
	{
		ck_assert_str_eq(rpnOut, "");
	}

#test rpn_Input1
	char infixOut[MAX_OUTPUT_STRING];
	returnType out = RPNToInfix("abc-+",infixOut);
	
	ck_assert_int_eq(out,SUCCESS);

	if(out == SUCCESS)
	{
		ck_assert_str_eq(infixOut, "a+(b-c)");
	}

#test rpn_Input2
	char infixOut[MAX_OUTPUT_STRING];
	returnType out = RPNToInfix("ab+c-",infixOut);
	
	ck_assert_int_eq(out,SUCCESS);

	if(out == SUCCESS)
	{
		ck_assert_str_eq(infixOut, "(a+b)-c");
	}

#test rpn_Input3
	char *infixOut;
	returnType out = RPNToInfix("lmn^/o*p-",infixOut);
	
	ck_assert_int_eq(out,SUCCESS);

	if(out == SUCCESS)
	{
		ck_assert_str_eq(infixOut, "((l/(m^n))*o)-p");
	}

#test rpn_Input4
	char infixOut[MAX_OUTPUT_STRING];
	returnType out = RPNToInfix("vw/x^yz-*",infixOut);
	
	ck_assert_int_eq(out,SUCCESS);

	if(out == SUCCESS)
	{
		ck_assert_str_eq(infixOut, "((v/w)^x)*(y-z)");
	}

#test rpn_Input5
	char infixOut[MAX_OUTPUT_STRING];
	returnType out = RPNToInfix("ag+ba-c+cedf^*+^*",infixOut);
	
	ck_assert_int_eq(out,SUCCESS);

	if(out == SUCCESS)
	{
		ck_assert_str_eq(infixOut, "(a+g)*(((b-a)+c)^(c+(e*(d^f))))");
	}

#test rpn_Boundary_Limit_Check
	char infixOut[MAX_OUTPUT_STRING];
	// input string is null
	returnType out = RPNToInfix("",infixOut);
	
	ck_assert_int_eq(out,ERROR_INPUT_OUT_OF_BOUNDS);

	if(out == SUCCESS)
	{
		ck_assert_str_eq(infixOut, "");
	}

#test rpn_Input_Brace_Check
	char infixOut[MAX_OUTPUT_STRING];
    // Note:rpn input should not contain braces, hence braces are undefined characters
	returnType out = RPNToInfix("lm(n^/o)*p-",infixOut);
	
	ck_assert_int_eq(out,ERROR_UNDEFINED_CHARACTER);

	if(out == SUCCESS)
	{
		ck_assert_str_eq(infixOut, "");
	}

#test rpn_Undefined_Character_Check
	char infixOut[MAX_OUTPUT_STRING];
    // Note:Numbers are undefined characters
	returnType out = RPNToInfix("l8n^/o)*p-",infixOut);
	
	ck_assert_int_eq(out,ERROR_UNDEFINED_CHARACTER);

	if(out == SUCCESS)
	{
		ck_assert_str_eq(infixOut, "");
	}

#test rpn_Uppercase_Character_Check
	char infixOut[MAX_OUTPUT_STRING];
    // Note:Uppercase charcters are undefined characters. Only lowercase characters are allowed
	returnType out = RPNToInfix("Ab+c-",infixOut);
	
	ck_assert_int_eq(out,ERROR_UNDEFINED_CHARACTER);

	if(out == SUCCESS)
	{
		ck_assert_str_eq(infixOut, "");
	}


#test rpn_Incorrect_Operand_Number_Check
	char infixOut[MAX_OUTPUT_STRING];
   // Incorrect number of operands in input expression
	returnType out = RPNToInfix("abcd-*bc/pqm+-",infixOut);
	
	ck_assert_int_eq(out,ERROR_INVALID_INPUT_EXPR);

	if(out == SUCCESS)
	{
		ck_assert_str_eq(infixOut, "");
	}

#test rpn_Incorrect_Operator_Number_Check
	char infixOut[MAX_OUTPUT_STRING];
   // Incorrect number of operator in input expression
	returnType out = RPNToInfix("pq+/*-bc/mcm+-",infixOut);
	
	ck_assert_int_eq(out,ERROR_INVALID_INPUT_EXPR);

	if(out == SUCCESS)
	{
		ck_assert_str_eq(infixOut, "");
	}

#test rpn_White_Space_Character_Check
	char infixOut[MAX_OUTPUT_STRING];
    // Note:white spaces are undefined characters
	returnType out = RPNToInfix("ab + c-",infixOut);
	
	ck_assert_int_eq(out,ERROR_UNDEFINED_CHARACTER);

	if(out == SUCCESS)
	{
		ck_assert_str_eq(infixOut, "");
	}





