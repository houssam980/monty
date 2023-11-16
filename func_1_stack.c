#include "monty.h"


/**
 * stack_addi - Add a node to the stack
 * @nw_nd: Pointer to the new node
 * @ln:  line number
 * Return : Nothing to return
 */
void stack_addi(stack_t **nw_nd, __attribute__((unused))unsigned int ln)
{
stack_t *temp;

if (nw_nd == NULL || *nw_nd == NULL)
exit(EXIT_FAILURE);
if (head == NULL)
{
head = *nw_nd;
return;
}
temp = head;
head = *nw_nd;
head->next = temp;
temp->prev = head;
}


/**
 * stack_print - Add a node to the stack
 * @stack:node of the stack
 * @ln_num: line number
 * Return: Nothing to return
 */
void stack_print(stack_t **stack, unsigned int ln_num)
{
stack_t *temp;
(void) ln_num;
if (stack == NULL)
exit(EXIT_FAILURE);
temp = *stack;
while (temp != NULL)
{
printf("%d\n", temp->n);
temp = temp->next;
}
}

/**
 * pop_it - Add a node to the stack
 * @stack:node of the stack.
 * @ln_num:line number
 */
void pop_it(stack_t **stack, unsigned int ln_num)
{
stack_t *temp;
if (stack == NULL || *stack == NULL)
too_err(7, ln_num);
temp = *stack;
*stack = temp->next;
if (*stack != NULL)
(*stack)->prev = NULL;
free(temp);
}

/**
 * print_it_top - Print node of the stack
 * @stack: node of the stack
 * @ln_num: line number
 * Return : Nothing to return
 */
void print_it_top(stack_t **stack, unsigned int ln_num)
{
if (stack == NULL || *stack == NULL)
too_err(6, ln_num);
printf("%d\n", (*stack)->n);
}
