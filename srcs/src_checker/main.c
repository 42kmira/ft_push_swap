/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinu <xinu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 16:40:40 by marvin            #+#    #+#             */
/*   Updated: 2019/12/21 20:42:31 by xinu             ###   ########.fr       */
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
	stack_a = create_stack_from_list(&args[1]);

	// insert_by_value(stack_b, 12);
	// insert_by_value(stack_b, 11);

	printf(PURPLE"Stack_A\n"COLOR_RESET);
	print_stack(stack_a);
	// printf(PURPLE"Stack_B\n"COLOR_RESET);
	// print_stack(stack_b);

	// sa(stack_a, stack_b);
	// printf(PURPLE"Stack_A\n"COLOR_RESET);
	// print_stack(stack_a);

	// sb(stack_a, stack_b);
	// printf(PURPLE"Stack_B\n"COLOR_RESET);
	// print_stack(stack_b);

	// printf(BOLDGREEN"Doing OP: pa\n");

	// pa(stack_a, stack_b);
	// sb(stack_a, stack_b);
	// printf(PURPLE"Stack_A\n"COLOR_RESET);
	// print_stack(stack_a);
	// printf(PURPLE"Stack_B\n"COLOR_RESET);
	// print_stack(stack_b);

	// printf(BOLDGREEN"Doing OP: pb\n");
	// pb(stack_a, stack_b);
	// printf(PURPLE"Stack_A\n"COLOR_RESET);
	// print_stack(stack_a);
	// printf(PURPLE"Stack_B\n"COLOR_RESET);
	// print_stack(stack_b);
	(void)stack_b;
	(void)aa;
	return (0);
}
