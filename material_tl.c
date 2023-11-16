#include "monty.h"

/**
 * opn_fl - open a file
 * @fl_nm: the file namepath
 * Return: Nothing To Return
 */

void opn_fl(char *fl_nm)
{
FILE *fd = fopen(fl_nm, "r");
if (fl_nm == NULL || fd == NULL)
err_cd(2, fl_nm);
rd_fl(fd);
fclose(fd);
}


/**
 * rd_fl - read a file
 * @fd: pointer to file
 * Return: Nothing To Return
 */

void rd_fl(FILE *fd)
{
int line_number, format = 0;
char *buffer = NULL;
size_t lengh = 0;
for (line_number = 1; getline(&buffer, &lengh, fd) != -1; line_number++)
{
format = prs_ln(buffer, line_number, format);
}
free(buffer);
}


/**
 * ln_num - Separates each line
 * @buffer: line from the file
 * @line_number: line number
 * @format:  storage format
 * Return: Returns 0 if is stack, 1 if queue.
 */

int prs_ln(char *buffer, int ln_num, int format)
{
char *opcode, *value;
const char *delim = "\n ";
if (buffer == NULL)
err_cd(4);
opcode = strtok(buffer, delim);
if (opcode == NULL)
return (format);
value = strtok(NULL, delim);
if (strcmp(opcode, "stack") == 0)
return (0);
if (strcmp(opcode, "queue") == 0)
return (1);
fd_fun(opcode, value, ln_num, format);
return (format);
}

/**
 * fd_fun - find function
 * @opcode: opcode
 * @value: argument
 * @format: storage format
 * @ln: line number
 * Return: Nothing To Return
 */
void fd_fun(char *opcode, char *value, int ln, int format)
{
int iterate;
int flag;

instruction_t func_list[] = {
{"push", stack_addi},
{"pall", stack_print},
{"pint", print_it_top},
{"pop", pop_it},
{"nop", noth},
{"swap", swap_nd},
{"add", add_nd},
{"sub", sub_nd},
{"div", div_nd},
{"mul", mul_nd},
{"mod", mod_nd},
{"pchar", print_char},
{"pstr", print_str},
{"rotl", rot},
{"rotr", rotr},
{NULL, NULL}
};
if (opcode[0] == '#')
return;
for (flag = 1, iterate = 0; func_list[iterate].opcode != NULL; iterate++)
{
if (strcmp(opcode, func_list[iterate].opcode) == 0)
{
cll_fun(func_list[iterate].f, opcode, value, ln, format);
flag = 0;
}
}
if (flag == 1)
err_cd(3, ln, opcode);
}


/**
 * cll_fun - Call function
 * @func: function to be called
 * @op: str opcode
 * @val: str numeric value
 * @ln: line numeber
 * @format: Format
 * Return: Nothing To Return
 */
void cll_fun(op_func func, char *op, char *val, int ln, int format)
{
stack_t *node;
int flags;
int iterate;
flags = 1;
if (strcmp(op, "push") == 0)
{
if (val != NULL && val[0] == '-')
{
val = val + 1;
flags = -1;
}
if (val == NULL)
err_cd(5, ln);
for (iterate = 0; val[iterate] != '\0'; iterate++)
{
if (isdigit(val[iterate]) == 0)
err_cd(5, ln);
}
node = ct_node(atoi(val) * flags);
if (format == 0)
func(&node, ln);
if (format == 1)
add_que(&node, ln);
}
else
func(&head, ln);
}

