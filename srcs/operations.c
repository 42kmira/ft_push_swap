/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 12:40:47 by kmira             #+#    #+#             */
/*   Updated: 2020/01/17 01:46:57 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	sa(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*first;
	t_node	*second;
	t_node	*last;

	if (stack_a == NULL || stack_a->head == NULL)
		return ;
	first = stack_a->head;
	if (is_only_node(first))
		return ;
	second = first->next;
	last = first->prev;

	last->next = second;

	first->next = second->next;
	first->prev = second;

	second->prev = last;
	second->next = first;
	add_move_counter();
	(void)stack_b;
}

void	sb(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*first;
	t_node	*second;
	t_node	*last;

	if (stack_b == NULL || stack_b->head == NULL)
		return ;
	first = stack_b->head;
	if (is_only_node(first))
		return ;
	second = first->next;
	last = first->prev;

	last->next = second;

	first->next = second->next;
	first->prev = second;

	second->prev = last;
	second->next = first;
	add_move_counter();
	(void)stack_a;
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a, stack_b);
	subtract_move_counter();
	sb(stack_a, stack_b);
	subtract_move_counter();
	add_move_counter();
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	// t_node	*elem;

	// elem = pop(stack_b);
	// insert_by_node(stack_a, elem);
	(void)stack_a;
	(void)stack_b;
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	// t_node	*elem;

	// elem = pop(stack_a);
	// insert_by_node(stack_b, elem);
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

