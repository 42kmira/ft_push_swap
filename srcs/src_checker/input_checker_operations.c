/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checker_operations.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 17:08:17 by kmira             #+#    #+#             */
/*   Updated: 2020/01/19 19:24:10 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		create_jump_table(t_operation *jump_table, t_stack *stack_a, t_stack *stack_b)
{
	int			i;
	char		buffer[OPERATIONS_READ_BUFFER + 1];

	ft_bzero(buffer, sizeof(buffer));
	while ((errno != EINVAL) && read(STDIN_FILENO, buffer, OPERATIONS_READ_BUFFER))
	{
		i = 0;
		while (jump_table[i].operation != NULL)
		{
			if (ft_strcmp(jump_table[i].op_name, buffer) == 0)
				break ;
			i++;
		}
		if (jump_table[i].operation == NULL)
		{
			errno = EINVAL;
			break ;
		}
		else
			jump_table[i].operation(stack_a, stack_b);
		ft_bzero(buffer, sizeof(buffer));
	}
}

/*
** Clean way to create a jump table when:
** 	global variables are not allowed
** 	initialization at declarations is not allowed
**
** The compilier automagically calulates the amount of
** elements in the array.
*/

void		get_user_input(t_stack *stack_a, t_stack *stack_b)
{
	create_jump_table((t_operation[])
		{
			{sa, "sa\n\0\0"},
			{sb, "sb\n\0\0"},
			{ss, "ss\n\0\0"},
			{pa, "pa\n\0\0"},
			{pb, "pb\n\0\0"},
			{ra, "ra\n\0\0"},
			{rb, "rb\n\0\0"},
			{rr, "rr\n\0\0"},
			{rra, "rra\n\0"},
			{rrb, "rrb\n\0"},
			{rrr, "rrr\n\0"},
			{NULL, ""}
		}
	, stack_a, stack_b);
}
