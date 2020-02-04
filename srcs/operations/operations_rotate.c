/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 00:25:19 by kmira             #+#    #+#             */
/*   Updated: 2020/02/03 23:32:07 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	ra(t_stack *stack_a, t_stack *stack_b)
{
	buffer_output_str("ra\n", 0);
	add_move_counter();
	if (stack_a == NULL || stack_a->head == NULL)
		return ;
	stack_a->head = stack_a->head->next;
	(void)stack_b;
}

void	rb(t_stack *stack_a, t_stack *stack_b)
{
	buffer_output_str("rb\n", 0);
	add_move_counter();
	if (stack_b == NULL || stack_b->head == NULL)
		return ;
	stack_b->head = stack_b->head->next;
	(void)stack_a;
}

void	rra(t_stack *stack_a, t_stack *stack_b)
{
	buffer_output_str("rra\n", 0);
	add_move_counter();
	if (stack_a == NULL || stack_a->head == NULL)
		return ;
	stack_a->head = stack_a->head->prev;
	(void)stack_b;
}

void	rrb(t_stack *stack_a, t_stack *stack_b)
{
	buffer_output_str("rrb\n", 0);
	add_move_counter();
	if (stack_b == NULL || stack_b->head == NULL)
		return ;
	stack_b->head = stack_b->head->prev;
	(void)stack_a;
}
