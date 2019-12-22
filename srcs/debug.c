/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinu <xinu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 17:03:25 by xinu              #+#    #+#             */
/*   Updated: 2019/12/21 20:46:14 by xinu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

void	print_stack(t_stack *stack)
{
	int	i;
	t_node *iter;

	if (stack == NULL)
		return ;
	iter = stack->top;
	i = 0;
	// printf("STACK has %d elements\n", stack->count);
	while (i < stack->count)
	{
		printf("NODE: "CYAN"%3d"COLOR_RESET"\n", iter->value);
		iter = iter->next;
		i++;
	}
	// printf("ITER: %p\n", iter);
}
