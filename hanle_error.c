#include "monty.h"


/**
 * handle_error - check the rest of errors
 * @checkerr: error code
 */
void handle_error(int checkerr, ...)
{
	va_list args;
	char *operator;
	int occur;

	va_start(args, checkerr);
	switch (checkerr)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stark empty\n",
				va_arg(args, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stark\n",
				va_arg(args, int));
			break;
		case 8:
			occur = va_arg(args, unsigned int);
			operator = va_arg(args, char *);
			fprintf(stderr, "L%d: can't %s, stark too short\n", occur, operator);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(args, unsigned int));
			break;
		default:
			break;
	}
	nodefree();
	exit(EXIT_FAILURE);
}

/**
 * err - print error
 * @checkerr: detect approprioate error
 */
void err(int checkerr, ...)
{
	va_list args;
	char *operator;
	int occur;

	va_start(args, checkerr);
	switch (checkerr)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(args, char *));
			break;
		case 3:
			occur = va_arg(args, int);
			operator = va_arg(args, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", occur, operator);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(args, int));
			break;
		default:
			break;
	}
	nodefree();
	exit(EXIT_FAILURE);
}


/**
 * string_err - handles errors.
 * @checkerr: The error codes are the following:
 * (10) ~> The number inside a node is outside char bounds.
 * (11) ~> The stark is empty.
 */
void string_err(int checkerr, ...)
{
	va_list args;
	int occur;

	va_start(args, checkerr);
	occur = va_arg(args, int);
	switch (checkerr)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, checkval out of range\n", occur);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stark empty\n", occur);
			break;
		default:
			break;
	}
	nodefree();
	exit(EXIT_FAILURE);
}

/**
 * node_mod - addd 2 stacks
 * @stark: stack
 * @linenum: num of line
 */
void node_mod(stack_t **stark, unsigned int linenum)
{
	int sum;

	if (stark == NULL || *stark == NULL || (*stark)->next == NULL)

		handle_error(8, linenum, "mod");


	if ((*stark)->n == 0)
		handle_error(9, linenum);
	(*stark) = (*stark)->next;
	sum = (*stark)->n % (*stark)->prev->n;
	(*stark)->n = sum;
	free((*stark)->prev);
	(*stark)->prev = NULL;
}
