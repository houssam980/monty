#include "monty.h"

/**
 * noth - Do nothing
 * @stack: top node of the stack
 * @line_number:the line number
 * Return : Nothing to return
 */
void noth(stack_t **stack, unsigned int line_number)
{
(void)stack; /**casted to void*/
(void)line_number; /**casted to void*/
}


/**
 * swap_nd - Swap the top two elements
 * @stack: top node of the stack
 * @line_number:line number
 * Return : Nothing to return
 */
void swap_nd(stack_t **stack, unsigned int line_number)
{
stack_t *temp;
if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
too_err(8, line_number, "swap");
temp = (*stack)->next;
(*stack)->next = temp->next;
if (temp->next != NULL)
temp->next->prev = *stack;
temp->next = *stack;
(*stack)->prev = temp;
temp->prev = NULL;
*stack = temp;
}

/**
 * add_nde - Add the top two elements
 * @stack:top node of the stack.
 * @line_number:line number
 * Return : Nothing to return
 */
void add_nd(stack_t **stack, unsigned int line_number)
{
int sum;
if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
too_err(8, line_number, "add");
(*stack) = (*stack)->next;
sum = (*stack)->n + (*stack)->prev->n;
(*stack)->n = sum;
free((*stack)->prev);
(*stack)->prev = NULL;
}


/**
 * sub_nd - Add top two elements of the stack
 * @stack: top node of the stack
 * @line_number:line number
 * Return : Nothing to return
 */
void sub_nd(stack_t **stack, unsigned int line_number)
{
int sum;
if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
too_err(8, line_number, "sub");
(*stack) = (*stack)->next;
sum = (*stack)->n - (*stack)->prev->n;
(*stack)->n = sum;
free((*stack)->prev);
(*stack)->prev = NULL;
}








/**
 * div_nd - top two elements of the stack
 * @stack: top node of the stack.
 * @line_number: line number
 * Return : Nothing to return
 */
void div_nd(stack_t **stack, unsigned int line_number)
{
int sum;
if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
too_err(8, line_number, "div");
if ((*stack)->n == 0)
too_err(9, line_number);
(*stack) = (*stack)->next;
sum = (*stack)->n / (*stack)->prev->n;
(*stack)->n = sum;
free((*stack)->prev);
(*stack)->prev = NULL;
}
