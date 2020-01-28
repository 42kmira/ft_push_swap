/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 16:40:43 by marvin            #+#    #+#             */
/*   Updated: 2020/01/28 05:58:20 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	begin_merging(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*stop;
	t_node	*iter;
	t_node	*head;

	iter = stack_a->head;
	stop = stack_a->head;
	stop = stop->next;
	while (stop->value > iter->value)
	{
		iter = iter->next;
		stop = stop->next;
	}
	if (stop == stack_a->head)
		stop = stack_a->head->prev;

	while (stack_a->head != stop)
	{
		if (stack_b->head != NULL &&
			stack_a->head->value < stack_b->head->value)
		{
			ra(stack_a, stack_b);
		}
		else if (stack_b->head != NULL &&
			stack_a->head->value > stack_b->head->value)
		{
			pa(stack_a, stack_b);
			ra(stack_a, stack_b);
		}
		else if (stack_b->head == NULL)
		{
			ra(stack_a, stack_b);
		}
		else
			printf("Error! something something at %d\n", stack_a->head->value);
	}

	head = stop->next;
	while (stack_b->head != NULL)
	{
		if (stack_b->head->value < stack_a->head->value)
		{
			pa(stack_a, stack_b);
			ra(stack_a, stack_b);
		}
		else if (stack_b->head->value > stack_a->head->value && stack_a->head != head)
			ra(stack_a, stack_b);
		else
		{
			pa(stack_a, stack_b);
			ra(stack_a, stack_b);
		}
	}
}

void	merge_groups(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*iter;
	t_node	*group1;
	t_node	*group2;


	//finds the location of group2
	group1 = stack_a->head;
	group2 = stack_a->head;
	iter = group2;
	group2 = group2->next;
	while (iter->value < group2->value)
	{
		iter = iter->next;
		group2 = group2->next;
	}

	// print_stacks_detail(stack_a, stack_b);
	//Doesn't push to stack_b until it is necessary
	while (stack_a->head->value < group2->value)
		ra(stack_a, stack_b);
	if (stack_a->head != group2)
		pb(stack_a, stack_b);
	//group2 is assured to be in stack_a, therefore stack_a will never be empty
	while (stack_a->head != group2)
	{
		pb(stack_a, stack_b);
		rb(stack_a, stack_b);
	}
	begin_merging(stack_a, stack_b);
	// print_stacks_detail(stack_a, stack_b);
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

	merge_groups(stack_a, stack_b);
	merge_groups(stack_a, stack_b);
	merge_groups(stack_a, stack_b);

	print_stacks_detail(stack_a, stack_b);
	printf("MOVES: %d\n", counter_interface(READ, 0));
	(void)aa;
	return (0);
}
