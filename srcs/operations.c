/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinu <xinu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 12:40:47 by kmira             #+#    #+#             */
/*   Updated: 2019/12/21 18:23:22 by xinu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	sa(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*third;
	t_node	*tmp;

	if (stack_a->count <= 1)
	{
		printf(RED"Not enough elements for this operation\n"COLOR_RESET);
		return ;
	}
	tmp = stack_a->top;
	third = (tmp->next)->next;
	stack_a->top = tmp->next;
	stack_a->top->next = tmp;
	tmp->next = third;
	add_move_counter();
	(void)stack_a;
	(void)stack_b;
}

void	sb(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*third;
	t_node	*tmp;

	if (stack_b->count <= 1)
	{
		printf(RED"Not enough elements for this operation\n"COLOR_RESET);
		return ;
	}
	tmp = stack_b->top;
	third = (tmp->next)->next;
	stack_b->top = tmp->next;
	stack_b->top->next = tmp;
	tmp->next = third;
	add_move_counter();
	(void)stack_a;
	(void)stack_b;
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a, stack_b);
	subtract_move_counter();
	sb(stack_a, stack_b);
	subtract_move_counter();
	add_move_counter();
	(void)stack_a;
	(void)stack_b;
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*elem;

	elem = pop(stack_b);
	insert_by_node(stack_a, elem);
	(void)stack_a;
	(void)stack_b;
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*elem;

	elem = pop(stack_a);
	insert_by_node(stack_b, elem);
	(void)stack_a;
	(void)stack_b;
}

void	ra(t_stack *stack_a, t_stack *stack_b)
{
	(void)stack_a;
	(void)stack_b;
}

void	rb(t_stack *stack_a, t_stack *stack_b)
{
	(void)stack_a;
	(void)stack_b;
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	(void)stack_a;
	(void)stack_b;
}

void	rra(t_stack *stack_a, t_stack *stack_b)
{
	(void)stack_a;
	(void)stack_b;
}

void	rrb(t_stack *stack_a, t_stack *stack_b)
{
	(void)stack_a;
	(void)stack_b;
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	(void)stack_a;
	(void)stack_b;
}

