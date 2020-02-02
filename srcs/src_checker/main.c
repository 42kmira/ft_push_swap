/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 16:40:40 by marvin            #+#    #+#             */
/*   Updated: 2020/02/01 16:33:51 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*
** The binary tree sorts and checks for duplicated integers in the
** programs arguements (char **args). I use a binary tree because
** data will be inserted in log2(l), where l is the amount of
** leaves currently in the tree. As such the total complexity is
** log2(n!) where n is the total amount of valid arguements.
**
** It should be noted that is assuming the average case, where the
** data is randomly sorted. Worst case preformance is O(n^2). Where
** the list is mostly or completely sorted in reverse order.
*/

int		main(int aa, char **args)
{
	t_stack			*stack_a;
	t_stack			*stack_b;
	t_binary_tree	*root;
	int				status;

	status = 0;
	root = NULL;
	if (aa <= 1)
	{
		printf(RED"Not enough arguements!\n"COLOR_RESET);
		return (0);
	}
	else
	{
		stack_a = create_stack_from_list(&args[1], &root);
		stack_b = init_stack();
		get_user_input(stack_a, stack_b);
		if (errno == EINVAL)
			write(STDERR_FILENO, "Error\n", 6);
		else
			status = cmp_stack_to_sorted_tree(stack_a, root);
		free_stacks(stack_a, stack_b);
		free_tree(root);
	}
	if (status == 1 && errno == 0)
		printf("OK\n");
	else if (errno == 0)
		printf("KO\n");
	system("leaks checker");
	return (0);
}
