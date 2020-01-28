/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 12:40:47 by kmira             #+#    #+#             */
/*   Updated: 2020/01/25 04:23:38 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	sa(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*first;
	t_node	*second;
	t_node	*last;
	t_node	*third;

	add_move_counter();
	if (stack_a == NULL || stack_a->head == NULL)
		return ;
	first = stack_a->head;
	if (is_only_node(first) == 0)
	{
		second = first->next;
		if (is_only_two_nodes(first, second))
			stack_a->head = second;
		else
		{
			third = second->next;
			last = first->prev;
			last->next = second;
			if (last->prev == second)
				last->prev = first;
			first->next = second->next;
			first->prev = second;
			second->prev = last;
			second->next = first;
			third->prev = first;
			stack_a->head = second;
		}
	}
	(void)stack_b;
}

void	sb(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*first;
	t_node	*second;
	t_node	*last;
	t_node	*third;

	add_move_counter();
	if (stack_b == NULL || stack_b->head == NULL)
		return ;
	first = stack_b->head;
	if (is_only_node(first) == 0)
	{
		second = first->next;
		if (is_only_two_nodes(first, second))
			stack_b->head = second;
		else
		{
			third = second->next;
			last = first->prev;
			last->next = second;
			if (last->prev == second)
				last->prev = first;
			first->next = second->next;
			first->prev = second;
			second->prev = last;
			second->next = first;
			third->prev = first;
			stack_b->head = second;
		}
	}
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
	t_node	*elem;

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

	elem = pop(stack_a);
	if (elem != NULL)
		insert_by_node(stack_b, elem);
	add_move_counter();
	(void)stack_a;
	(void)stack_b;
}

void	ra(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a == NULL || stack_a->head == NULL)
		return ;
	stack_a->head = stack_a->head->next;
	(void)stack_b;
}

void	rb(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b == NULL || stack_b->head == NULL)
		return ;
	stack_b->head = stack_b->head->next;
	(void)stack_a;
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	ra(stack_a, stack_b);
	subtract_move_counter();
	rb(stack_a, stack_b);
	subtract_move_counter();
	add_move_counter();
}

void	rra(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a == NULL || stack_a->head == NULL)
		return ;
	stack_a->head = stack_a->head->prev;
	(void)stack_b;
}

void	rrb(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b == NULL || stack_b->head == NULL)
		return ;
	stack_b->head = stack_b->head->prev;
	(void)stack_a;
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	rra(stack_a, stack_b);
	subtract_move_counter();
	rrb(stack_a, stack_b);
	subtract_move_counter();
	add_move_counter();
}
