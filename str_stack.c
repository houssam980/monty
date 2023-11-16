#include "monty.h"

/**
 * print_char - Print Ascii value
 * @stack: top node of the stack
 * @line_number:the line number
 * Return : Nothing to return
 */
void print_char(stack_t **stack, unsigned int line_number)
{
int ascii;
if (stack == NULL || *stack == NULL)
str_err(11, line_number);
ascii = (*stack)->n;
if (ascii < 0 || ascii > 127)
str_err(10, line_number);
printf("%c\n", ascii);
}

/**
 * print_str - Print a string
 * @stack:top node of the stack
 * @ln: line number
 * Return : Nothing to return
 */
void print_str(stack_t **stack, __attribute__((unused))unsigned int ln)
{
int ascii;
stack_t *temp;
if (stack == NULL || *stack == NULL)
{
printf("\n");
return;
}
temp = *stack;
while (temp != NULL)
{
ascii = temp->n;
if (ascii <= 0 || ascii > 127)
break;
printf("%c", ascii);
temp = temp->next;
}
printf("\n");
}

/**
 * rot_f - Rotate the first node
 * @stack:top node of the stack
 * @ln: line number
 * Return : Nothing to return
 */
void rot_f(stack_t **stack, __attribute__((unused))unsigned int ln)
{
stack_t *tmp;
if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
return;
tmp = *stack;
while (tmp->next != NULL)
tmp = tmp->next;
tmp->next = *stack;
(*stack)->prev = tmp;
*stack = (*stack)->next;
(*stack)->prev->next = NULL;
(*stack)->prev = NULL;
}


/**
 * rot_l - Rotates the last node
 * @stack: top node of the stack
 * @ln: line number
 */
void rot_l(stack_t **stack, __attribute__((unused))unsigned int ln)
{
stack_t *tmp;
if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
return;
tmp = *stack;
while (tmp->next != NULL)
tmp = tmp->next;
tmp->next = *stack;
tmp->prev->next = NULL;
tmp->prev = NULL;
(*stack)->prev = tmp;
(*stack) = tmp;
}

