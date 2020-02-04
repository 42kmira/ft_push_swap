/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 00:27:27 by kmira             #+#    #+#             */
/*   Updated: 2020/02/03 23:32:18 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	swap_nodes(t_node *node_1, t_node *node_2)
{
	t_node	*prior_node;
	t_node	*after_node;

	prior_node = node_1->prev;
	after_node = node_2->next;
	if (prior_node != node_2 && after_node != node_1)
	{
		prior_node->next = node_2;
		node_2->next = node_1;
		node_1->next = after_node;
		after_node->prev = node_1;
		node_1->prev = node_2;
		node_2->prev = prior_node;
	}
}

void	sa(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*first;
	t_node	*second;

	buffer_output_str("sa\n", 0);
	add_move_counter();
	if (stack_a == NULL || stack_a->head == NULL)
		return ;
	first = stack_a->head;
	second = first->next;
	swap_nodes(first, second);
	stack_a->head = second;
	(void)stack_b;
}

void	sb(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*first;
	t_node	*second;

	buffer_output_str("sb\n", 0);
	add_move_counter();
	if (stack_b == NULL || stack_b->head == NULL)
		return ;
	first = stack_b->head;
	second = first->next;
	swap_nodes(first, second);
	stack_b->head = second;
	(void)stack_a;
}
