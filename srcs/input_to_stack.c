/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_to_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 20:29:57 by xinu              #+#    #+#             */
/*   Updated: 2020/01/18 16:22:29 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

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
	if (str[i] != '\0' || i == 0)
		errno = EINVAL;
	return (result * sign);
}

t_stack	*create_stack_from_list(char **args)
{
	int				i;
	int				value;
	t_stack			*result;
	t_binary_tree	*root;

	i = 0;
	root = NULL;
	result = init_stack();
	while (args[i] != NULL)
		i++;
	if (args[i] == NULL)
		i--;
	while (i >= 0 && errno != EINVAL)
	{
		value = mini_atoi(args[i]);
		if (errno == EINVAL)
			return (NULL);
		insert_by_value(result, value);
		if (root == NULL)
			root = init_binary_node(value);
		else
			tree_insert(root, value);
		i--;
	}
	printf("Printing Tree \n");
	print_tree(root);
	printf("\n");
	return (result);
}
