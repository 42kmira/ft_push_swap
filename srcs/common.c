/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 16:46:38 by marvin            #+#    #+#             */
/*   Updated: 2020/02/06 10:26:57 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int		count_nodes(t_stack *stack)
{
	int		result;
	t_node	*start;
	t_node	*iter;

	result = 0;
	start = NULL;
	iter = stack->head;
	while (iter != start)
	{
		if (start == NULL)
			start = iter;
		iter = iter->next;
		result++;
	}
	return (result);
}
