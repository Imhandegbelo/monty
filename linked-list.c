#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * queue_node - adds a node to a stack (queue_mode)
 * @stack: stack head
 * @n: number of the node
 *
 * Return: newly created node, if memory allocation fails, the function will
 * return NULL.
 */
stack_t *queue_node(stack_t **stack, const int n)
{
	stack_t *new = malloc(sizeof(stack_t));
	stack_t *current = *stack;

	if (!new)
	{
		free(new);
		return (NULL);
	}
	new->n = n;

	if (!*stack)
	{
		new->next = NULL;
		new->prev = NULL;
		*stack = new;
		return (new);
	}

	while (current)
	{
		if (!current->next)
		{
			new->next = NULL;
			new->prev = current;
			current->next = new;
			break;
		}
		current = current->next;
	}

	return (new);
}

/**
 * add_node - adds a node to the start of a stack
 * @stack: stack head
 * @n: number for the new node
 *
 * Return: newly created node, else NULL if creation fails
 */
stack_t *add_node(stack_t **stack, const int n)
{
	stack_t *current = malloc(sizeof(stack_t));

	if (!current)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(current);
		return (NULL);
	}
	current->n = n;

	current->next = *stack;
	current->prev = NULL;
	if (*stack)
		(*stack)->prev = current;

	*stack = current;

	return (current);
}

/**
 * print_stack - prints the contents of a stack
 * @stack: stack head
 *
 * Return: number of elements of the list
 */
size_t print_stack(const stack_t *stack)
{
	size_t total = 0;

	while (stack)
	{
		printf("%d\n", stack->n);
		stack = stack->next;
		total++;
	}

	return (total);
}

/**
 * free_stack - frees linked list
 * @stack: list head
 *
 * Return: no return
 */
void free_stack(stack_t *stack)
{
	stack_t *current = stack;
	stack_t *next;

	if (stack)
	{
		next = stack->next;
		while (current)
		{
			free(current);
			current = next;
			if (next)
				next = next->next;
		}
	}
}
