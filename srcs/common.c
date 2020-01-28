/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 16:46:38 by marvin            #+#    #+#             */
/*   Updated: 2020/01/23 14:18:02 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

char	is_only_two_nodes(t_node *first, t_node *second)
{
	char	result;

	result = 0;
	if (second->next == first)
		result = 1;
	return (result);
}
