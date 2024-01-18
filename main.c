#include "monty.h"

stack_t *head = NULL;

/**
 * main - main
 * @argc: arguments count
 * @argv: list of arguments
 * Return: always 0
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file_handle(argv[1]);
	nodefree();
	return (0);
}

/**
 * create_node - noe create
 * @n: number
 * Return: pointer
 */
stack_t *create_node(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		err(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}

/**
 * nodefree - free
 *
 * Return: nothing
 */
void nodefree(void)
{
	stack_t *tmp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}


/**
 * queueadd - add queue
 * @new_node: new node
 * @numline: line number
 */
void queueadd(stack_t **new_node, unsigned int numline)
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
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *new_node;
	(*new_node)->prev = tmp;

}


