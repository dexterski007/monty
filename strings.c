#include "monty.h"


/**
 * pstr - pstr
 * @stark: stack
 * @numline: linue number
 */
void pstr(stack_t **stark, __attribute__((unused))unsigned int numline)
{
	int chara;
	stack_t *tmp;

	if (stark == NULL || *stark == NULL)
	{
		printf("\n");
		return;
	}

	tmp = *stark;
	while (tmp != NULL)
	{
		chara = tmp->n;
		if (chara <= 0 || chara > 127)
			break;
		printf("%c", chara);
		tmp = tmp->next;
	}
	printf("\n");
}
/**
 * pchar - pchjar
 * @stark: stack
 * @numline: linue number
 */
void pchar(stack_t **stark, unsigned int linenum)
{
	int chara;

	if (stark == NULL || *stark == NULL)
		string_err(11, linenum);
	chara = (*stark)->n;
	if (chara < 0 || chara > 127)
	string_err(10, linenum);
	printf("%c\n", chara);
}


/**
 * rotr - Rotr
 * @stark: stack
 * @numline: linue number
 */
void rotr(stack_t **stark, __attribute__((unused))unsigned int numline)
{
	stack_t *tmp;

	if (stark == NULL || *stark == NULL || (*stark)->next == NULL)
		return;

	tmp = *stark;

	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stark;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	(*stark)->prev = tmp;
	(*stark) = tmp;
}

/**
 * rotl - rotl
 * @stark: stack
 * @numline: linue number
 */
void rotl(stack_t **stark, __attribute__((unused))unsigned int numline)
{
	stack_t *tmp;

	if (stark == NULL || *stark == NULL || (*stark)->next == NULL)
		return;

	tmp = *stark;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stark;
	(*stark)->prev = tmp;
	*stark = (*stark)->next;
	(*stark)->prev->next = NULL;
	(*stark)->prev = NULL;
}

