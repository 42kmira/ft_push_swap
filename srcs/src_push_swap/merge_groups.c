/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_groups.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 18:58:35 by kmira             #+#    #+#             */
/*   Updated: 2020/02/05 05:20:31 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	forward_rotate(t_stack *stack_a, t_stack *stack_b, int amount)
{
	int	i;

	i = 0;
	while (i < amount)
	{
		ra(stack_a, stack_b);
		i++;
	}
}

void	reverse_rotate(t_stack *stack_a, t_stack *stack_b, int amount)
{
	int	i;

	i = 0;
	while (i < amount)
	{
		rra(stack_a, stack_b);
		i++;
	}
}

int		rotates_until_start(t_stack *stack, t_node **iter_addr)
{
	int		result;
	t_node	*iter;

	result = 0;
	iter = stack->head;
	while (iter->value < iter->next->value)
	{
		iter = iter->next;
		result++;
	}
	*iter_addr = iter->next;
	result++;
	return (result);
}

int		calc_forward_rots(t_stack *stack_a, t_stack *stack_b)
{
	int		result;
	t_node	*insert;
	t_node	*iter;

	result = 0;
	iter = stack_a->head;
	insert = stack_b->head;
	if (insert->value < iter->value)
		result = rotates_until_start(stack_a, &iter);
	if (iter->prev->value < insert->value && iter->value < iter->prev->value)
		return (0);
	while (iter->value < insert->value)
	{
		iter = iter->next;
		result++;
		if (iter->value < iter->prev->value)
			break ;
	}
	if (iter == stack_a->head)
		return (0);
	return (result);
}

void	start_merge(t_stack *stack_a, t_stack *stack_b)
{
	int		size;
	int		forward_rots;
	int		reverse_rots;

	while (stack_b->head != NULL)
	{
		forward_rots = calc_forward_rots(stack_a, stack_b);
		reverse_rots = count_nodes(stack_a) - forward_rots;
		if (forward_rots <= reverse_rots)
			forward_rotate(stack_a, stack_b, forward_rots);
		else
			reverse_rotate(stack_a, stack_b, reverse_rots);
		pa(stack_a, stack_b);
	}
	size = count_nodes(stack_a);
	if (stack_a->head->rank <= size / 2)
		while (stack_a->head->rank != 1)
			rra(stack_a, stack_b);
	else
		while (stack_a->head->rank != 1)
			ra(stack_a, stack_b);
}
