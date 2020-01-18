/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 16:40:40 by marvin            #+#    #+#             */
/*   Updated: 2020/01/18 14:51:18 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		main(int aa, char **args)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_b = init_stack();
	if (aa <= 1)
	{
		printf(RED"Not enough arguements!\n"COLOR_RESET);
		return (0);
	}
	else
	{
		stack_a = create_stack_from_list(&args[1]);
		stack_b = init_stack();
		get_user_input(stack_a, stack_b);
		if (errno == EINVAL)
			write(STDERR_FILENO, "Error\n", 6);
		else
			print_stack(stack_a);
	}

	return (0);
}
