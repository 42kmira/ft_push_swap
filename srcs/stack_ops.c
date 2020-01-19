/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 12:04:14 by kmira             #+#    #+#             */
/*   Updated: 2020/01/18 16:21:22 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(*stack));
	stack->count = 0;
	stack->head = NULL;
	return (stack);
}

t_node	*pop(t_stack *stack)
{
	t_node	*first;
	t_node	*second;
	t_node	*last;

	if (stack == NULL || stack->head == NULL)
		return (NULL);
	first = stack->head;
	second = first->next;
	last = first->prev;
	first->next = NULL;
	first->prev = NULL;
	if (first == last)
		stack->head = NULL;
	else
	{
		stack->head = second;
		last->next = second;
		second->prev = last;
	}
	return (first);
}

void	insert_by_value(t_stack *stack, int value)
{
	t_node	*new_elem;
	t_node	*first;
	t_node	*last;

	if (stack == NULL)
		return ;
	new_elem = malloc(sizeof(*new_elem));
	new_elem->value = value;
	if (stack->head == NULL)
	{
		stack->head = new_elem;
		new_elem->next = new_elem;
		new_elem->prev = new_elem;
	}
	else
	{
		first = stack->head;
		last = first->prev;
		new_elem->next = first;
		new_elem->prev = last;
		last->next = new_elem;
		first->prev = new_elem;
		stack->head = new_elem;
	}
}

void	insert_by_node(t_stack *stack, t_node *elem)
{
	t_node	*first;
	t_node	*last;

	if (stack == NULL)
		return ;
	if (stack->head == NULL)
	{
		stack->head = elem;
		elem->next = elem;
		elem->prev = elem;
	}
	else
	{
		first = stack->head;
		last = first->prev;
		elem->next = first;
		elem->prev = last;
		last->next = elem;
		first->prev = elem;
		stack->head = elem;
	}
}

