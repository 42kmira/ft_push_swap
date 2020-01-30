/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_groups.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 18:58:35 by kmira             #+#    #+#             */
/*   Updated: 2020/01/30 01:52:23 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	start_merge(t_stack *stack_a, t_stack *stack_b)
{
	int		forward_rots;
	int		reverse_rots;

	printf(BOLDLIGHT_PURPLE"!!!!!!!!!!!!!!!!!!!!!!!!STARTING MERGE!!!!!!!!!!!!!!!!!!!!!!!!\n"COLOR_RESET);
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
