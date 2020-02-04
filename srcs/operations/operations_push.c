/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 12:40:47 by kmira             #+#    #+#             */
/*   Updated: 2020/02/03 23:31:58 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*elem;

	buffer_output_str("pa\n", 0);
	elem = pop(stack_b);
	if (elem != NULL)
		insert_by_node(stack_a, elem);
	add_move_counter();
	(void)stack_a;
	(void)stack_b;
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*elem;

	buffer_output_str("pb\n", 0);
	elem = pop(stack_a);
	if (elem != NULL)
		insert_by_node(stack_b, elem);
	add_move_counter();
	(void)stack_a;
	(void)stack_b;
}
