#include "monty.h"

/**
 * pint - prints the value at the top of the stack
 *
 * @dlist: head of the linked list
 * @c_line: line number
 * Return: no return
 */
void pint(stack_t **dlist, unsigned int c_line)
{
	if (*dlist == NULL || *(dlist)->next == NULL)
	{
		fprintf(stderr, "can't pint, stack empty\n", c_line);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*dlist)->n);
}

/**
 * pop - removes the top element of the stack
 *
 * @dlist: head of the linked list
 * @c_line: line number
 * Return: no return
 */
void pop(stack_t **dlist, unsigned int c_line)
{
	stack_t *to_free;

	if (dlist == NULL || *dlist == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", c_line);
		exit(EXIT_FAILURE);
	}
	to_free = *dlist;
	*dlist = (*dlist)->next;
	free(to_free);
}

/**
 * swap - swaps the top two elements of the stack
 *
 * @dlist: head of the linked list
 * @c_line: line number
 * Return: no return
 */
void swap(stack_t **dlist, unsigned int c_line)
{
	stack_t *top, *second, *third;

	if (*dlist == NULL || (*dlist)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", c_line);
		exit(EXIT_FAILURE);
	}

	top = *dlist;
	second = top->next;
	third = second->next;
	top->next = third;
	top->prev = second;
	second->next = top;
	second->prev = NULL;

	if (third != NULL)
	{
		third->prev = top;
	}
	*dlist = second;
}
/**
 * add - sums specific lines together
 *
 * @dlist: head of the linked list
 * @c_line: line number;
 * Return: no return
 */


void add(stack_t **dlist, unsigned int c_line)
{
	int stack_size = 0;
	stack_t *current = NULL;

	current = *dlist;

	while (current != NULL)
	{
		stack_size++;
		current = current->next;
	}

	if stack_size < 2
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", c_line);
		exit(EXIT_FAILURE);
	}

	current = (*dlist)->next;
	current->n += (*dlist)->n;
	pop(dlist, c_line);
}

/**
 * nop - doesn't do anythinhg
 *
 * @dlist: head of the linked list
 * @c_line: line number;
 * Return: no return
 */

void nop(stack_t **dlist, unsigned int c_line)
{
	(void)dlist;
	(void)c_line;
}
