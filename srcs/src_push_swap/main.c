/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 16:40:43 by marvin            #+#    #+#             */
/*   Updated: 2020/01/28 19:17:47 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	find_best_lock_sequence(stack_a, size);

	// print_stacks_detail(stack_a, stack_b);

	// t_node	*stop = stack_a->head->prev;
	// while (stack_a->head != stop)
	// {
	// 	if (stack_a->head->locked)
	// 		ra(stack_a, stack_b);
	// 	else
	// 		pb(stack_a, stack_b);
	// }
	// while (stack_b->head != NULL)
	// 	pa(stack_a, stack_b);
	// print_stacks_detail(stack_a, stack_b);

	sort_entire_stack_by_groups_of_three(stack_a, stack_b, size);

	print_stacks_detail(stack_a, stack_b);
	printf("MOVES: %d\n", counter_interface(READ, 0));
	(void)aa;
	return (0);
}
