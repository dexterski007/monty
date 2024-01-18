#include "monty.h"

/**
 * nop_stack - do nothing
 * @stark: pointer to pointer to stack top
 * @linenum: line number
 */
void nop_stack(stack_t **stark, unsigned int linenum)
{
	(void)stark;
	(void)linenum;
}


/**
 * swap_stack - swap stacl
 * @stark: stack
 * @linenum: line number
 */
void swap_stack(stack_t **stark, unsigned int linenum)
{
	stack_t *tmp;

	if (stark == NULL || *stark == NULL || (*stark)->next == NULL)
		handle_error(8, linenum, "swap");
	tmp = (*stark)->next;
	(*stark)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *stark;
	tmp->next = *stark;
	(*stark)->prev = tmp;
	tmp->prev = NULL;
	*stark = tmp;
}

/**
 * node_add - add node
 * @stark: stack pointer
 * @linenum: line number
 */
void node_add(stack_t **stark, unsigned int linenum)
{
	int sum;

	if (stark == NULL || *stark == NULL || (*stark)->next == NULL)
		handle_error(8, linenum, "add");

	(*stark) = (*stark)->next;
	sum = (*stark)->n + (*stark)->prev->n;
	(*stark)->n = sum;
	free((*stark)->prev);
	(*stark)->prev = NULL;
}


/**
 * node_sub - substract nodes
 * @stark: stack pointer
 * @linenum: line number
 */
void node_sub(stack_t **stark, unsigned int linenum)
{
	int sum;

	if (stark == NULL || *stark == NULL || (*stark)->next == NULL)

		handle_error(8, linenum, "sub");


	(*stark) = (*stark)->next;
	sum = (*stark)->n - (*stark)->prev->n;
	(*stark)->n = sum;
	free((*stark)->prev);
	(*stark)->prev = NULL;
}


/**
 * node_div - div nodes
 * @stark: stack pointer
 * @linenum: line number
 */
void node_div(stack_t **stark, unsigned int linenum)
{
	int sum;

	if (stark == NULL || *stark == NULL || (*stark)->next == NULL)
		handle_error(8, linenum, "div");

	if ((*stark)->n == 0)
		handle_error(9, linenum);
	(*stark) = (*stark)->next;
	sum = (*stark)->n / (*stark)->prev->n;
	(*stark)->n = sum;
	free((*stark)->prev);
	(*stark)->prev = NULL;
}
