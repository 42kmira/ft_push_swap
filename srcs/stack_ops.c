/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinu <xinu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 12:04:14 by kmira             #+#    #+#             */
/*   Updated: 2019/12/21 20:28:33 by xinu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(*stack));
	stack->count = 0;
	stack->top = NULL;
	stack->last = NULL;
	return (stack);
}

t_node	*pop(t_stack *stack)
{
	t_node	*result;

	if (stack == NULL || stack->top == NULL)
		return (NULL);
	if (stack->last == stack->top)
		stack->last = NULL;
	result = stack->top;
	stack->top = stack->top->next;
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
	// 	stack->top->prev = new_elem;
	new_elem->value = value;
	new_elem->next = stack->top;
	// new_elem->prev = stack->last;
	stack->top = new_elem;
	stack->count = stack->count + 1;
	if (stack->last == NULL)
		stack->last = new_elem;
}

void	insert_by_node(t_stack *stack, t_node *elem)
{
	if (stack == NULL)
		return ;
	if (stack->last == NULL)
		stack->last = elem;
	elem->next = stack->top;
	// stack->top->prev = elem;
	stack->top = elem;
	stack->count = stack->count + 1;
}
