/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 17:03:25 by xinu              #+#    #+#             */
/*   Updated: 2020/01/28 19:08:33 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

void	print_stack(t_stack *stack)
{
	t_node *iter;
	t_node *first;

	if (stack == NULL)
		return ;
	iter = stack->head;
	first = iter;
	if (iter != NULL)
	{
		printf("NODE: "CYAN"%3d"COLOR_RESET"\n", iter->value);
		iter = iter->next;
	}
	while (iter != first)
	{
		printf("NODE: "CYAN"%3d"COLOR_RESET"\n", iter->value);
		iter = iter->next;
	}
	// printf("ITER: %p\n", iter);
}

void	print_stack_reverse(t_stack *stack)
{
	t_node *iter;
	t_node *first;

	if (stack == NULL)
		return ;
	iter = stack->head;
	first = iter;
	if (iter != NULL)
	{
		printf("NODE: "CYAN"%3d"COLOR_RESET"\n", iter->value);
		iter = iter->prev;
	}
	while (iter != first)
	{
		printf("NODE: "CYAN"%3d"COLOR_RESET"\n", iter->value);
		iter = iter->prev;
	}
	// printf("ITER: %p\n", iter);
}

void	print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	t_node *start_a;
	t_node *start_b;
	t_node *iter_a;
	t_node *iter_b;

	start_a = NULL;
	start_b = NULL;
	if (stack_a->head != NULL)
		start_a = stack_a->head;
	if (stack_b->head != NULL)
		start_b = stack_b->head;
	iter_a = start_a;
	iter_b = start_b;

	printf(MAGENTA"NEW STACK PRINT\n"COLOR_RESET);

	if (iter_a == NULL)
		printf("NODE: NULL      ");
	else
	{
		printf("NODE: "CYAN"%-10d"COLOR_RESET, iter_a->value);
		iter_a = iter_a->next;
	}
	if (iter_b == NULL)
		printf("NODE: NULL      \n");
	else
	{
		printf("NODE: "CYAN"%-10d"COLOR_RESET"\n", iter_b->value);
		iter_b = iter_b->next;
	}

	while (iter_a != start_a || iter_b != start_b)
	{
		if (iter_a == start_a)
			printf("NODE: NULL      ");
		else
		{
			printf("NODE: "CYAN"%-10d"COLOR_RESET, iter_a->value);
			iter_a = iter_a->next;
		}
		if (iter_b == start_b)
			printf("NODE: NULL      \n");
		else
		{
			printf("NODE: "CYAN"%-10d"COLOR_RESET"\n", iter_b->value);
			iter_b = iter_b->next;
		}
	}
}

void	print_detailed(t_node **iter)
{
	t_node *node;

	node = *iter;
	if (node->locked == LOCKED_NODE)
		printf("NODE: "GREEN"%-10d %-3d "COLOR_RESET, node->value, node->rank);
	else
		printf("NODE: "CYAN"%-10d %-3d "COLOR_RESET, node->value, node->rank);
	*iter = (*iter)->next;
}

void	print_stacks_detail(t_stack *stack_a, t_stack *stack_b)
{
	t_node *start_a;
	t_node *start_b;
	t_node *iter_a;
	t_node *iter_b;

	start_a = NULL;
	start_b = NULL;
	if (stack_a->head != NULL)
		start_a = stack_a->head;
	if (stack_b->head != NULL)
		start_b = stack_b->head;
	iter_a = start_a;
	iter_b = start_b;

	printf(MAGENTA"NEW STACK PRINT\n"COLOR_RESET);

	if (iter_a == NULL)
		printf("NODE: NULL           ");
	else
		print_detailed(&iter_a);
	if (iter_b == NULL)
		printf("NODE: NULL         ");
	else
		print_detailed(&iter_b);
	printf("\n");

	while (iter_a != start_a || iter_b != start_b)
	{
		if (iter_a == start_a)
			printf("NODE: NULL           ");
		else
			print_detailed(&iter_a);
		if (iter_b == start_b)
			printf("NODE: NULL         ");
		else
			print_detailed(&iter_b);
		printf("\n");
	}
}
