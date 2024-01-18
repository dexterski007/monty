#include "monty.h"


/**
 * push_stack - stack push
 * @new_node: node
 * @numline: num of line
 */
void push_stack(stack_t **new_node, unsigned int numline)
{
	stack_t *tmp;

	(void)numline;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	tmp = head;
	head = *new_node;
	head->next = tmp;
	tmp->prev = head;
}


/**
 * pall_stack - print all
 * @stark: pointer to pointer
 * @linenum: line number
 */
void pall_stack(stack_t **stark, unsigned int linenum)
{
	stack_t *tmp;

	(void) linenum;
	if (stark == NULL)
		exit(EXIT_FAILURE);
	tmp = *stark;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * pop_stack - pop from stack
 * @stark: pointer to pointer to top stack
 * @linenum: line number
 */
void pop_stack(stack_t **stark, unsigned int linenum)
{
	stack_t *tmp;

	if (stark == NULL || *stark == NULL)
		handle_error(7, linenum);

	tmp = *stark;
	*stark = tmp->next;
	if (*stark != NULL)
		(*stark)->prev = NULL;
	free(tmp);
}

/**
 * pint_stack - print stack
 * @stark: pointer to stack
 * @linenum: line number
 */
void pint_stack(stack_t **stark, unsigned int linenum)
{
	if (stark == NULL || *stark == NULL)
		handle_error(6, linenum);
	printf("%d\n", (*stark)->n);
}
