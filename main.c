#include "monty.h"
stack_t *head = NULL;

/**
 * main - entry point
 * @argc: arguments count
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
	open_file(argv[1]);
	free_nodes();
	return (0);
}

/**
 * create - Creates a node.
 * @number: Number to go inside the node.
 * Return: Upon sucess a pointer to the node. Otherwise NULL.
 */
stack_t *create(int number)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		error(4);
	node->next = NULL;
	node->prev = NULL;
	node->number = number;
	return (node);
}

/**
 * free - Frees nodes in the stack.
 */
void free(void)
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
 * add_to_queue - Adds a node to the queue.
 * @node: Pointer to the new node.
 * @line: line number of the opcode.
 */
void add_to_queue(stack_t **node, __attribute__((unused))unsigned int line)
{
	stack_t *tmp;

	if (node == NULL || *node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *node;
		return;
	}
	tmp = head;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *node;
	(*node)->prev = tmp;

}
