/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_groups.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 18:58:35 by kmira             #+#    #+#             */
/*   Updated: 2020/01/28 03:32:26 by kmira            ###   ########.fr       */
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
