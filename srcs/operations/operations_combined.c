/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_combined.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 00:25:01 by kmira             #+#    #+#             */
/*   Updated: 2020/02/03 23:31:48 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	buffer_output_str("rr\n", 0);
	ra(stack_a, stack_b);
	subtract_move_counter();
	rb(stack_a, stack_b);
	subtract_move_counter();
	add_move_counter();
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	buffer_output_str("rr\n", 0);
	rra(stack_a, stack_b);
	subtract_move_counter();
	rrb(stack_a, stack_b);
	subtract_move_counter();
	add_move_counter();
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	buffer_output_str("ss\n", 0);
	sa(stack_a, stack_b);
	subtract_move_counter();
	sb(stack_a, stack_b);
	subtract_move_counter();
	add_move_counter();
}
