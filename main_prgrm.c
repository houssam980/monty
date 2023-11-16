#include "monty.h"
stack_t *head = NULL;

/**
 * main - entry point
 * @argc: arguments cts
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
opn_fl(argv[1]);
free_nodes();
return (0);
}




/**
 * ct_node - Create a node
 * @num: Number
 * Return: return pointer to the node, Otherwise NULL
 */
stack_t *ct_node(int num)
{
stack_t *node;

node = malloc(sizeof(stack_t));
if (node == NULL)
err_cd(4);
node->next = NULL;
node->prev = NULL;
node->n = num;
return (node);
}



/**
 * free_nodes - Free node in the stack
 * Return: Nothing to return
 */
void free_nodes(void)
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
 * add_que - Add a node to the queue
 * @new_node: Pointer to the new node
 * @ln: line number of the opcode
 */
void add_que(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
stack_t *tmp;
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

