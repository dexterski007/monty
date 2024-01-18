#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stark (or queue)
 * @n: integer
 * @prev: points to the previous element of the stark (or queue)
 * @next: points to the next element of the stark (or queue)
 *
 * Description: doubly linked list node structure
 * for stark, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - op_detect and its function
 * @op_detect: the op_detect
 * @f: function to handle the op_detect
 *
 * Description: op_detect and its function
 * for stark, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *op_detect;
        void (*f)(stack_t **stark, unsigned int linenum);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

/*main.c*/
stack_t *create_node(int n);
void nodefree(void);
void queueadd(stack_t **, unsigned int);
void node_mult(stack_t **, unsigned int);
int len_chars(FILE *);

/*handl_error.c*/
void handle_error(int checkerr, ...);
void err(int checkerr, ...);
void string_err(int checkerr, ...);
void node_mod(stack_t **, unsigned int);

/*handl_line.c*/
void file_handle(char *fname);
int linebyline(char *buff, int linenum, int style);
void fparse(FILE *);
void call_fun(op_func, char *, char *, int, int);
void find_func(char *, char *, int, int);

/*stark_hanle.c*/
void push_stack(stack_t **, unsigned int);
void pint_stack(stack_t **, unsigned int);
void pop_stack(stack_t **, unsigned int);
void pall_stack(stack_t **, unsigned int);

/*operations.c*/
void nop_stack(stack_t **, unsigned int);
void swap_stack(stack_t **, unsigned int);
void node_add(stack_t **, unsigned int);
void node_sub(stack_t **, unsigned int);
void node_div(stack_t **, unsigned int);

/*strings.c*/
void pchar(stack_t **, unsigned int);
void pstr(stack_t **, unsigned int);
void rotl(stack_t **, unsigned int);
void rotr(stack_t **, unsigned int);

#endif
