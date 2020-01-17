/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 12:04:14 by kmira             #+#    #+#             */
/*   Updated: 2020/01/17 00:16:32 by kmira            ###   ########.fr       */
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
	t_node	*result;

	if (stack == NULL || stack->head == NULL)
		return (NULL);
	result = stack->head;
	stack->head = stack->head->next;
	stack->count = stack->count - 1;
	return (result);
}

void	insert_by_value(t_stack *stack, int value)
{
	t_node	*new_elem;

	if (stack == NULL)
		return ;
	new_elem = malloc(sizeof(*new_elem));
	// if (stack->last != NULL)
	// 	stack->head->prev = new_elem;
	new_elem->value = value;
	new_elem->next = stack->head;
	// new_elem->prev = stack->last;
	stack->head = new_elem;
	stack->count = stack->count + 1;
}

void	insert_by_node(t_stack *stack, t_node *elem)
{
	if (stack == NULL)
		return ;
	elem->next = stack->head;
	// stack->head->prev = elem;
	stack->head = elem;
	stack->count = stack->count + 1;
}

