/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 16:40:43 by marvin            #+#    #+#             */
/*   Updated: 2020/01/30 01:50:50 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	forward_rotate(t_stack *stack_a, t_stack *stack_b, int amount)
{
	int	i;

	i = 0;
	while (i < amount)
	{
		ra(stack_a, stack_b);
		i++;
	}
}

void	reverse_rotate(t_stack *stack_a, t_stack *stack_b, int amount)
{
	int	i;

	i = 0;
	while (i < amount)
	{
		rra(stack_a, stack_b);
		i++;
	}
}

int		calc_forward_rots(t_stack *stack_a, t_stack *stack_b)
{
	int		result;
	t_node	*insert;
	t_node	*iter;
	t_node	*start;

	result = 0;
	iter = stack_a->head;
	insert = stack_b->head;
	start = stack_a->head;
	if (insert->value < iter->value)
	{
		while (iter->next->value > iter->value)
		{
			iter = iter->next;
			result++;
		}
		iter = iter->next;
		start = iter;
		result++;
	}
	if (iter->prev->value < insert->value && iter->value < iter->prev->value)
		return (0);
	while (iter->value < insert->value)
	{
		iter = iter->next;
		result++;
		if (iter->value < iter->prev->value)
			break ;
	}
	if (iter == stack_a->head)
		return (0);
	return (result);
}

int		count_nodes(t_stack *stack)
{
	int		result;
	t_node	*start;
	t_node	*iter;

	result = 0;
	start = NULL;
	iter = stack->head;
	while (iter != start)
	{
		if (start == NULL)
			start = iter;
		iter = iter->next;
		result++;
	}
	return (result);
}

int		lock_push(t_stack *stack_a, t_stack *stack_b)
{
	int		size;
	t_node	*stop;
	t_node	*iter;
	t_node	*last_locked_node;

	// print_stacks_detail(stack_a, stack_b);
	size = count_nodes(stack_a) - 1;
	if (size < 3)
		return (LAST_SORT);
	find_best_lock_sequence(stack_a, size);
	iter = stack_a->head;
	last_locked_node = NULL;
	stop = stack_a->head->prev;
	while (iter != stop)
	{
		if (iter->locked == LOCKED_NODE)
			last_locked_node = iter;
		iter = iter->next;
	}
	while (stack_a->head != last_locked_node)
	{
		if (stack_a->head->locked == LOCKED_NODE)
			pb(stack_a, stack_b);
		else
			ra(stack_a, stack_b);
	}
	if (stack_a->head->local_rank == LOCKED_NODE)
		pb(stack_a, stack_b);
	// printf("MOVES: %d\n", counter_interface(READ, 0));
	return (0);
}

int		main(int aa, char **args)
{
	t_stack			*stack_a;
	t_stack			*stack_b;
	t_binary_tree	*root;
	int				*sorted_array;
	int				size;

	stack_a = create_stack_from_list(&args[1], &root);
	stack_b = init_stack();
	size = tree_to_array(root, &sorted_array);
	init_rank(stack_a, root);

	int status;

	status = 0;
	while (status != LAST_SORT)
		status = lock_push(stack_a, stack_b);

	sort_by_group_of_three(stack_a, stack_b);
	printf("MOVES: %d\n", counter_interface(READ, 0));
	// print_stacks_detail(stack_a, stack_b);
	start_merge(stack_a, stack_b);

	print_stacks_detail(stack_a, stack_b);
	printf("MOVES: %d\n", counter_interface(READ, 0));
	(void)aa;
	return (0);
}
