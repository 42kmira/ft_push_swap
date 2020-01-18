/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 16:46:38 by marvin            #+#    #+#             */
/*   Updated: 2020/01/17 06:50:50 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	comm_test(char *str)
{
	printf("Common files work %s\n", str);
}

char	is_only_node(t_node *node)
{
	char	result;

	result = 0;
	if (node == NULL)
		result = 0;
	else if (node->next == node)
		result = 1;
	else
		result = 0;
	return (result);
}
