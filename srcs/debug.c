/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 17:03:25 by xinu              #+#    #+#             */
/*   Updated: 2020/01/17 01:46:13 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

void	print_stack(t_stack *stack)
{
	t_node *iter;
	t_node *first;

	if (stack == NULL)
		return ;
	iter = stack->head;
	first = iter;
	if (iter != NULL)
	{
		printf("NODE: "CYAN"%3d"COLOR_RESET"\n", iter->value);
		iter = iter->next;
	}
	while (iter != first)
	{
		printf("NODE: "CYAN"%3d"COLOR_RESET"\n", iter->value);
		iter = iter->next;
	}
	// printf("ITER: %p\n", iter);
}
