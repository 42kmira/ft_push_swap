/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_to_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 20:29:57 by xinu              #+#    #+#             */
/*   Updated: 2020/02/06 10:34:44 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include <limits.h>

int		is_digit(char c)
{
	if ('0' <= c && c <= '9')
		return (1);
	else
		return (0);
}

int		mini_atoi(char *str)
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

int		has_multiple_nums(char *str)
{
	int		i;
	int		result;

	i = 0;
	result = 0;
	if (str[i] == '-')
		i++;
	while ('0' <= str[i] && str[i] <= '9')
		i++;
	if (str[i] == '\0')
		result = 0;
	else if (str[i] == ' ')
		i++;
	if (('0' <= str[i] && str[i] <= '9') || str[i] == '-')
		result = 1;
	return (result);
}

t_stack	*create_stack_a(char **args, t_binary_tree **root, int aa)
{
	t_stack	*stack_a;
	char	**numbers;
	int		numbers_need_free;
	int		i;

	numbers = &args[1];
	numbers_need_free = 0;
	if (aa == 2 && has_multiple_nums(args[1]) == 1)
	{
		numbers = ft_strsplit(args[1], ' ');
		numbers_need_free = 1;
	}
	stack_a = create_stack_from_list(numbers, root);
	if (numbers_need_free == 1)
	{
		i = 0;
		while (numbers[i] != NULL)
		{
			free(numbers[i]);
			i++;
		}
		free(numbers);
	}
	return (stack_a);
}
