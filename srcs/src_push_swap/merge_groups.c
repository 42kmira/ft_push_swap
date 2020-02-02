/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_groups.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 18:58:35 by kmira             #+#    #+#             */
/*   Updated: 2020/01/30 02:07:14 by kmira            ###   ########.fr       */
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

int		calc_forward_rots(t_stack *stack_a, t_stack *stack_b)
{
	int		result;
	t_node	*insert;
	t_node	*iter;
	t_node	*start;

	result = 0;
	iter = stack_a->head;
	insert = stack_b->head;
	start = stack_a->head;
	if (insert->value < iter->value)
	{
		while (iter->next->value > iter->value)
		{
			iter = iter->next;
			result++;
		}
		iter = iter->next;
		start = iter;
		result++;
	}
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
	int		forward_rots;
	int		reverse_rots;

	// printf(BOLDLIGHT_PURPLE"!!!!!!!!!!!!!!!!!!!!!!!!STARTING MERGE!!!!!!!!!!!!!!!!!!!!!!!!\n"COLOR_RESET);
	while (stack_b->head != NULL)
	{
		forward_rots = calc_forward_rots(stack_a, stack_b);
		reverse_rots =  count_nodes(stack_a) - forward_rots;
		// printf("Forward rot: %d\n", forward_rots);
		// printf("Reverse rot: %d\n", reverse_rots);
		if (forward_rots <= reverse_rots)
			forward_rotate(stack_a, stack_b, forward_rots);
		else
			reverse_rotate(stack_a, stack_b, reverse_rots);
		// print_stacks_detail(stack_a, stack_b);
		pa(stack_a, stack_b);
		// print_stacks_detail(stack_a, stack_b);
	}
}
