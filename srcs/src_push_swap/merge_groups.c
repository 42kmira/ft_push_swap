/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_groups.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 18:58:35 by kmira             #+#    #+#             */
/*   Updated: 2020/01/28 19:17:27 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	first_merge(t_stack *from, t_stack *stack_a, t_stack *stack_b)
{
	t_node	*first;
	t_node	*second;

	first = NULL;
	second = NULL;
	first = from->head;
	if (first)
		second = first->next;
	if (first == NULL || second == NULL)
		return ;
	if (first->value < second->value)
	{
		pb(stack_a, stack_b);
		pb(stack_a, stack_b);
		sb(stack_a, stack_b);
		printf("STACK B rev\n");
		print_stack_reverse(stack_b);
	}
	else
	{
		pb(stack_a, stack_b);
		pb(stack_a, stack_b);
	}
}

int	begin_merging(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*stop;
	t_node	*iter;
	t_node	*head;
	int		status;

	iter = stack_a->head;
	stop = stack_a->head;
	stop = stop->next;
	while (stop->value > iter->value)
	{
		iter = iter->next;
		stop = stop->next;
	}
	status = 0;
	if (stop == stack_a->head)
		status = LAST_SORT;

	if (status != LAST_SORT)
	{
		while (stack_a->head != stop)
		{
			if (stack_b->head != NULL &&
				stack_a->head->value < stack_b->head->value)
			{
				ra(stack_a, stack_b);
			}
			else if (stack_b->head != NULL &&
				stack_a->head->value > stack_b->head->value)
			{
				pa(stack_a, stack_b);
				ra(stack_a, stack_b);
			}
			else if (stack_b->head == NULL)
			{
				ra(stack_a, stack_b);
			}
			else
				printf("Error! something something at %d\n", stack_a->head->value);
		}

		head = stop->next;
		while (stack_b->head != NULL)
		{
			if (stack_b->head->value < stack_a->head->value)
			{
				pa(stack_a, stack_b);
				ra(stack_a, stack_b);
			}
			else if (stack_b->head->value > stack_a->head->value && stack_a->head != head)
				ra(stack_a, stack_b);
			else
			{
				pa(stack_a, stack_b);
				ra(stack_a, stack_b);
			}
		}
	}
	return (status);
}

int	merge_groups(t_stack *stack_a, t_stack *stack_b)
{
	int		result;
	t_node	*iter;
	t_node	*group1;
	t_node	*group2;

	//finds the location of group2
	group1 = stack_a->head;
	group2 = stack_a->head;
	iter = group2;
	group2 = group2->next;
	while (iter->value < group2->value)
	{
		iter = iter->next;
		group2 = group2->next;
	}

	// print_stacks_detail(stack_a, stack_b);
	//Doesn't push to stack_b until it is necessary
	while (stack_a->head->value < group2->value)
		ra(stack_a, stack_b);
	if (stack_a->head != group2)
		pb(stack_a, stack_b);
	//group2 is assured to be in stack_a, therefore stack_a will never be empty
	while (stack_a->head != group2)
	{
		pb(stack_a, stack_b);
		rb(stack_a, stack_b);
	}
	result = begin_merging(stack_a, stack_b);
	return (result);
	// print_stacks_detail(stack_a, stack_b);
}

void	merge_order(t_stack *stack_a, t_stack *stack_b)
{
	int status;

	status = 0;
	while (status != LAST_SORT)
		status = merge_groups(stack_a, stack_b);
}

