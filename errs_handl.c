#include "monty.h"

/**
 *  err_cd - handles errors
 * @err_code: error codes
 * Return : nothing to return
 */


void err_cd(int err_code, ...)
{
va_list arg;
char *op;
int l_num;
va_start(arg, err_code);
switch (err_code)
{
case 1:
fprintf(stderr, "USAGE: monty file\n");
break;
case 2:
fprintf(stderr, "Error: Can't open file %s\n",
va_arg(arg, char *));
break;
case 3:
l_num = va_arg(arg, int);
op = va_arg(arg, char *);
fprintf(stderr, "L%d: unknown instruction %s\n", l_num, op);
break;
case 4:
fprintf(stderr, "Error: malloc failed\n");
break;
case 5:
fprintf(stderr, "L%d: usage: push integer\n", va_arg(arg, int));
break;
default:
break;
}
free_nodes();
exit(EXIT_FAILURE);
}



/**
 * too_err - handles errors
 * @err_code: error code
 *Return: nothing to return
 */
void too_err(int err_code, ...)
{
va_list arg;
char *op;
int l_num;

va_start(arg, err_code);
switch (err_code)
{
case 6:
fprintf(stderr, "L%d: can't pint, stack empty\n",
va_arg(arg, int));
break;
case 7:
fprintf(stderr, "L%d: can't pop an empty stack\n",
va_arg(arg, int));
break;
case 8:
l_num = va_arg(arg, unsigned int);
op = va_arg(arg, char *);
fprintf(stderr, "L%d: can't %s, stack too short\n", l_num, op);
break;
case 9:
fprintf(stderr, "L%d: division by zero\n",
va_arg(arg, unsigned int));
break;
default:
break;
}
free_nodes();
exit(EXIT_FAILURE);
}




/**
 * str_err - handles errors
 * @err_code:error code
 * Return: Nothing to return
 */
void str_err(int err_code, ...)
{
va_list arg;
int l_num;
va_start(arg, err_code);
l_num = va_arg(arg, int);
switch (err_code)
{
case 10:
fprintf(stderr, "L%d: can't pchar, value out of range\n", l_num);
break;
case 11:
fprintf(stderr, "L%d: can't pchar, stack empty\n", l_num);
break;
default:
break;
}
free_nodes();
exit(EXIT_FAILURE);
}
