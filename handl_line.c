#include "monty.h"

/**
 * file_handle - handle file
 * @fname: filename
 */

void file_handle(char *fname)
{
	FILE *fpoint = fopen(fname, "r");

	if (fname == NULL || fpoint == NULL)
		err(2, fname);

	fparse(fpoint);
	fclose(fpoint);
}


/**
 * fparse - parse file
 * @fpoint: file pointer
 */

void fparse(FILE *fpoint)
{
	int linenum, style = 0;
	char *buff = NULL;
	size_t len = 0;

	for (linenum = 1; getline(&buff, &len, fpoint) != -1; linenum++)
	{
		style = linebyline(buff, linenum, style);
	}
	free(buff);
}


/**
 * linebyline - separate lines
 * @buff: buff
 * @linenum: numf of line
 * @style: style
 * Return: 0 or 1
 */

int linebyline(char *buff, int linenum, int style)
{
	char *op_detect, *checkval;
	const char *eol = "\n ";

	if (buff == NULL)
		err(4);

	op_detect = strtok(buff, eol);
	if (op_detect == NULL)
		return (style);
	checkval = strtok(NULL, eol);

	if (strcmp(op_detect, "stack") == 0)
		return (0);
	if (strcmp(op_detect, "queue") == 0)
		return (1);

	find_func(op_detect, checkval, linenum, style);
	return (style);
}

/**
 * find_func - find function
 * @op_detect: detect op
 * @checkval: check value
 * @style: style
 * @numline: num of line
 */
void find_func(char *op_detect, char *checkval, int numline, int style)
{
	int j;
	int fuse;

	instruction_t func_list[] = {
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{"push", push_stack},
		{"pall", pall_stack},
		{"pint", pint_stack},
		{"add", node_add},
		{"sub", node_sub},
		{"div", node_div},
		{"mul", node_mult},
		{"mod", node_mod},
		{"pop", pop_stack},
		{"nop", nop_stack},
		{"swap", swap_stack},
		{NULL, NULL}
	};

	if (op_detect[0] == '#')
		return;

	for (fuse = 1, j = 0; func_list[j].op_detect != NULL; j++)
	{
		if (strcmp(op_detect, func_list[j].op_detect) == 0)
		{
			call_fun(func_list[j].f, op_detect, checkval, numline, style);
			fuse = 0;
		}
	}
	if (fuse == 1)
		err(3, numline, op_detect);
}


/**
 * call_fun - call function
 * @func: function
 * @operator: operator
 * @val: value
 * @numline: num of line
 * @style: style
 */
void call_fun(op_func func, char *operator, char *val, int numline, int style)
{
	stack_t *node;
	int fuse;
	int j;

	fuse = 1;
	if (strcmp(operator, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			fuse = -1;
		}
		if (val == NULL)
			err(5, numline);
		for (j = 0; val[j] != '\0'; j++)
		{
			if (isdigit(val[j]) == 0)
				err(5, numline);
		}
		node = create_node(atoi(val) * fuse);
		if (style == 0)
			func(&node, numline);
		if (style == 1)
			queueadd(&node, numline);
	}
	else
		func(&head, numline);
}
