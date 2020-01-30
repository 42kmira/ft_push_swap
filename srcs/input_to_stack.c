/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_to_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 20:29:57 by xinu              #+#    #+#             */
/*   Updated: 2020/01/30 01:55:35 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include <limits.h>

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
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	if (str[i] == '-' && str[i + 1] != '\0')
	{
		i++;
		sign = -1;
	}
	while (is_digit(str[i]))
	{
		result = (result * 10) + (str[i] - '0');
		if (result * sign < INT_MIN || (sign == 1 && result > INT_MAX))
		{
			errno = EOVERFLOW | EINVAL;
			break ;
		}
		i++;
	}
	if (str[i] != '\0')
		errno = EINVAL;
	return (result * sign);
}

t_stack	*create_stack_from_list(char **args, t_binary_tree **root)
{
	int				i;
	int				value;
	t_stack			*result;

	i = 0;
	result = init_stack();
	while (args[i] != NULL)
		i++;
	if (args[i] == NULL)
		i--;
	while (i >= 0 && !(errno & EINVAL))
	{
		value = mini_atoi(args[i]);
		if (errno == EINVAL)
			return (NULL);
		insert_by_value(result, value);
		if (*root == NULL)
			*root = init_binary_node(value);
		else
			tree_insert(*root, value);
		i--;
	}
	return (result);
}
