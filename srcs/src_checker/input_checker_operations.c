/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checker_operations.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 17:08:17 by kmira             #+#    #+#             */
/*   Updated: 2020/02/05 22:40:54 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	do_command(t_operation *jump_table,
							t_stack *stack_a, t_stack *stack_b, char *str)
{
	int	i;

	i = 0;
	while (jump_table[i].operation != NULL)
	{
		if (ft_strcmp(jump_table[i].op_name, str) == 0)
			break ;
		i++;
	}
	if (jump_table[i].operation == NULL)
		errno = EINVAL;
	else
		jump_table[i].operation(stack_a, stack_b);
	ft_bzero(str, ft_strlen(str));
}

#define MAX_COMMAND_LEN 4

int		partial_command_stored(char *str, char *buffer, int *i)
{
	int	delim;
	int	result;

	result = 0;
	if (str[0] != '\0')
	{
		delim = ft_strchr(buffer, '\n') - buffer;
		if (0 <= delim && delim <= MAX_COMMAND_LEN - 2)
		{
			ft_strncat(str, buffer, delim + 1);
			*i = *i + delim + 1;
			result = 1;
		}
		else
		{
			errno = EINVAL;
		}
	}
	return (result);
}

int		calc_addon(char *buffer, int i, char *str)
{
	int	result;
	int	len;

	result = -1;
	if (buffer[i + 2] == '\n')
	{
		result = 3;
		ft_strncat(str, &buffer[i], result);
	}
	else if (buffer[i + 3] == '\n')
	{
		result = 4;
		ft_strncat(str, &buffer[i], result);
	}
	else
	{
		len = ft_strlen(&buffer[i]);
		if (0 <= len && len <= MAX_COMMAND_LEN - 1)
			ft_strncat(str, &buffer[i], len);
		else
			errno = EINVAL;
	}
	return (result);
}

void	create_jump_table(t_operation *jump_table,
							t_stack *stack_a, t_stack *stack_b)
{
	int			i;
	int			addon;
	char		temp[MAX_COMMAND_LEN * 2];
	char		buffer[OPS_READ_BUFFER + 1 + MAX_COMMAND_LEN];

	ft_bzero(temp, sizeof(temp));
	ft_bzero(buffer, sizeof(buffer));
	while ((errno != EINVAL) && read(STDIN_FILENO, buffer, OPS_READ_BUFFER))
	{
		i = 0;
		if (partial_command_stored(temp, buffer, &i) == 1)
			do_command(jump_table, stack_a, stack_b, temp);
		while (errno != EINVAL && buffer[i] != '\0')
		{
			addon = calc_addon(buffer, i, temp);
			if (addon != -1)
				do_command(jump_table, stack_a, stack_b, temp);
			else
				break ;
			i = i + addon;
		}
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

void	get_user_input(t_stack *stack_a, t_stack *stack_b)
{
	create_jump_table((t_operation[])
		{
			{sa, "sa\n"},
			{sb, "sb\n"},
			{ss, "ss\n"},
			{pa, "pa\n"},
			{pb, "pb\n"},
			{ra, "ra\n"},
			{rb, "rb\n"},
			{rr, "rr\n"},
			{rra, "rra\n"},
			{rrb, "rrb\n"},
			{rrr, "rrr\n"},
			{NULL, ""}
		}
	, stack_a, stack_b);
}
