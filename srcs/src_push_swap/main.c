/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 16:40:43 by marvin            #+#    #+#             */
/*   Updated: 2020/01/28 04:15:10 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	merge_groups(t_stack *stack_a, t_stack *stack_b)
{
	(void)stack_a;
	(void)stack_b;
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
	find_best_lock_sequence(stack_a, size);
	sort_entire_stack_by_groups_of_three(stack_a, stack_b, size);
	print_stacks_detail(stack_a, stack_b);
	(void)aa;
	return (0);
}
