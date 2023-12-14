#include "monty.h"

/**
 * error - Prints appropiate error messages determined by their error code.
 * @error_number: The error codes are the following:
 * (1) => The user does not give any file or more than one file to the program.
 * (2) => The file provided is not a file that can be opened or read.
 * (3) => The file provided contains an invalid instruction.
 * (4) => When the program is unable to malloc more memory.
 * (5) => When the parameter passed to the instruction "push" is not an int.
 * (6) => When the stack it empty for pint.
 * (7) => When the stack it empty for pop.
 * (8) => When stack is too short for operation.
 */
void error(int error_number, ...)
{
	va_list arguments;
	char *op;
	int line_number;

	va_start(arguments, error_number);
	switch (error_number)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(arguments, char *));
			break;
		case 3:
			line_number = va_arg(arguments, int);
			op = va_arg(arguments, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, op);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(arguments, int));
			break;
		default:
			break;
	}
	free();
	exit(EXIT_FAILURE);
}

/**
 * more_error - handles errors.
 * @error_number: The error codes are the following:
 * (6) => When the stack it empty for pint.
 * (7) => When the stack it empty for pop.
 * (8) => When stack is too short for operation.
 * (9) => Division by zero.
 */
void more_error(int error_number, ...)
{
	va_list arguments;
	char *op;
	int line_number;

	va_start(arguments, error_number);
	switch (error_number)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(arguments, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(arguments, int));
			break;
		case 8:
			line_number = va_arg(arguments, unsigned int);
			op = va_arg(arguments, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", line_number, op);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(arguments, unsigned int));
			break;
		default:
			break;
	}
	free();
	exit(EXIT_FAILURE);
}

/**
 * string_error - handles errors.
 * @error_number: The error codes are the following:
 * (10) ~> The number inside a node is outside ASCII bounds.
 * (11) ~> The stack is empty.
 */
void string_error(int error_number, ...)
{
	va_list arguments;
	int line_number;

	va_start(arguments, error_number);
	line_number = va_arg(arguments, int);
	switch (error_number)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
			break;
		default:
			break;
	}
	free();
	exit(EXIT_FAILURE);
}
