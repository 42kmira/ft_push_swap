/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checker_stack.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 20:29:57 by xinu              #+#    #+#             */
/*   Updated: 2020/01/17 01:46:55 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	is_digit(char c)
{
	if ('0' <= c && c <= '9')
		return (1);
	else
		return (0);
}

int	mini_atoi(char *str)
{
	int		i;
	int8_t	sign;
	int		result;

	i = 0;
	sign = 1;
	result = 0;
	if (str[i] == '\0')
	{
		printf(RED"Throw error here!\n"COLOR_RESET);
	}
	if (str[i] == '-')
	{
		i++;
		sign = -1;
	}
	while (is_digit(str[i]))
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	if (str[i] != '\0')
	{
		printf(RED"Throw error here!\n"COLOR_RESET);
	}
	return (result * sign);
}

t_stack	*create_stack_from_list(char **args)
{
	int		i;
	int		value;
	t_stack	*result;

	i = 0;
	result = init_stack();
	while (args[i] != NULL)
	{
		value = mini_atoi(args[i]);
		insert_by_value(result, value);
		i++;
	}
	return (result);
}
