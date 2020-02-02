/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 16:40:43 by marvin            #+#    #+#             */
/*   Updated: 2020/01/30 21:03:27 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		{
			// print_stacks_detail(stack_a, stack_b);
			if (stack_a->head->next->value > stack_a->head->prev->value && stack_a->head->next->value < stack_a->head->value)
			{
				if (stack_a->head->next->locked != LOCKED_NODE)
					sa(stack_a, stack_b);
			}
			ra(stack_a, stack_b);
		}
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
	// printf("MOVES: %d\n", counter_interface(READ, 0));
	// print_stacks_detail(stack_a, stack_b);
	start_merge(stack_a, stack_b);

	// print_stacks_detail(stack_a, stack_b);
	printf("MOVES: %d\n", counter_interface(READ, 0));
	(void)aa;
	return (0);
}
