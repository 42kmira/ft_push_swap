/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 16:40:43 by marvin            #+#    #+#             */
/*   Updated: 2020/01/22 23:43:55 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	first_merge(t_stack *from, t_stack *stack_a, t_stack *stack_b)
{
	t_node	*first;
	t_node	*second;

	first = NULL;
	second = NULL;
	first = from->head;
	if (first)
		second = first->next;
	if (first == NULL || second == NULL)
		return ;
	if (first->value < second->value)
	{
		pb(stack_a, stack_b);
		pb(stack_a, stack_b);
		sb(stack_a, stack_b);
	}
	else
	{
		pb(stack_a, stack_b);
		pb(stack_a, stack_b);
	}
}

int		main(int aa, char **args)
{
	t_stack			*stack_a;
	t_stack			*stack_b;
	t_binary_tree	*root;
	int				*sorted_array;

	stack_a = create_stack_from_list(&args[1], &root);
	stack_b = init_stack();

	int		i;
	int		size;

	i = 0;
	size = tree_to_array(root, &sorted_array);
	// while (i < size)
	// {
	// 	printf("NUM %d: %d\n", i, sorted_array[i]);
	// 	i++;
	// }
	print_stacks(stack_a, stack_b);
	first_merge(stack_a, stack_a, stack_b);
	print_stacks(stack_a, stack_b);
	first_merge(stack_a, stack_a, stack_b);

	// print_stack(stack_a);
	// printf("Stack B\n");
	// print_stack(stack_b);

	print_stacks(stack_a, stack_b);
	(void)aa;
	return (0);
}
