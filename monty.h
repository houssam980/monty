#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);



/**--------------------------------------------*/


void opn_fl(char *fl_nm);
int prs_ln(char *buffer, int ln_num, int format);
void rd_fl(FILE *);
int len_chars(FILE *);
void fd_fun(char *, char *, int, int);

stack_t *ct_node(int num);
void free_nodes(void);
void stack_print(stack_t **, unsigned int);
void stack_addi(stack_t **, unsigned int);
void add_que(stack_t **, unsigned int);

void cll_fun(op_func, char *, char *, int, int);

void print_it_top(stack_t **, unsigned int);
void pop_it(stack_t **, unsigned int);
void noth(stack_t **, unsigned int);
void swap_nd(stack_t **, unsigned int);


void add_nd(stack_t **, unsigned int);
void sub_nd(stack_t **, unsigned int);
void div_nd(stack_t **, unsigned int);
void mul_nd(stack_t **, unsigned int);
void mod_nd(stack_t **, unsigned int);


void print_char(stack_t **, unsigned int);
void print_str(stack_t **, unsigned int);
void rot_f(stack_t **, unsigned int);


void err_cd(int err_code, ...);
void too_err(int err_code, ...);
void str_err(int err_code, ...);
void rot_l(stack_t **, unsigned int);

#endif

