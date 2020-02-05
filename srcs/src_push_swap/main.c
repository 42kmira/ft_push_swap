/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 16:40:43 by marvin            #+#    #+#             */
/*   Updated: 2020/02/05 05:54:30 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		lock_push(t_stack *stack_a, t_stack *stack_b)
{
	int		size;
	t_node	*stop;
	t_node	*iter;
	t_node	*last_locked_node;

	size = count_nodes(stack_a) - 1;
	if (size < 3)
		return (LAST_SORT);
	find_best_lock_sequence(stack_a, size);
	iter = stack_a->head;
	stop = stack_a->head->prev;
	while (iter != stop)
	{
		if (iter->locked == LOCKED_NODE)
			last_locked_node = iter;
		iter = iter->next;
	}
	while (stack_a->head != last_locked_node)
		if (stack_a->head->locked == LOCKED_NODE)
			pb(stack_a, stack_b);
		else
			ra(stack_a, stack_b);
	pb(stack_a, stack_b);
	return (0);
}

int		main(int aa __attribute__((unused)), char **args)
{
	t_stack			*stack_a;
	t_stack			*stack_b;
	t_binary_tree	*root;
	int				*sorted_array;
	int				status;

	stack_a = create_stack_from_list(&args[1], &root);
	if ((errno & EINVAL) == 0)
	{
		stack_b = init_stack();
		tree_to_array(root, &sorted_array);
		init_rank(stack_a, root);
		status = cmp_stack_to_sorted_tree(stack_a, root);
		if (status == STACK_NOT_SORTED)
		{
			while (status != LAST_SORT)
				status = lock_push(stack_a, stack_b);
			sort_by_group_of_three(stack_a, stack_b);
			start_merge(stack_a, stack_b);
		}
		flush_buffer_str();
		free_stack(stack_a);
		free_stack(stack_b);
		free_tree(root);
		free(sorted_array);
	}
	return (0);
}
