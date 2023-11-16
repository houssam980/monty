#include "monty.h"

/**
 * mul_nodes - mul two elements
 * @stack: top node of the stack
 * @line_number: line number
 * Return: Nothing return
 */
void mul_nd(stack_t **stack, unsigned int line_number)
{
int mull;
if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
too_err(8, line_number, "mul");
(*stack) = (*stack)->next;
mull = (*stack)->n * (*stack)->prev->n;
(*stack)->n = mull;
free((*stack)->prev);
(*stack)->prev = NULL;
}

/**
 * mod_nodes - mod two elements
 * @stack: top node of the stack
 * @line_number: line number
 * Return: Nothing return
 */
void mod_nd(stack_t **stack, unsigned int line_number)
{
int modd;
if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
too_err(8, line_number, "mod");
if ((*stack)->n == 0)
too_err(9, line_number);
(*stack) = (*stack)->next;
modd = (*stack)->n % (*stack)->prev->n;
(*stack)->n = modd;
free((*stack)->prev);
(*stack)->prev = NULL;
}

