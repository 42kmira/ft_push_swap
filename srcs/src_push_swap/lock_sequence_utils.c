/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lock_sequence_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 22:44:13 by kmira             #+#    #+#             */
/*   Updated: 2020/02/03 22:48:54 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** The paramaters for this are a bit wild but it should be done like that.
** The first is the address of a 2D array. Hence the three stars.
** The second is the address of a 2D array of pointers:
** 		(t_node *) -> type
** 		(*) -> address (passing by address)
** 		(**) -> 2D array
*/

void	init_matrix(int ***matrix_address, t_node ****stack_ptrs_addr, int size)
{
	int		i;
	int		**matrix;
	t_node	***stack_ptrs;

	i = 0;
	matrix = malloc(sizeof(*matrix) * (size + 1));
	stack_ptrs = malloc(sizeof(*stack_ptrs) * (size + 1));
	while (i < size)
	{
		matrix[i] = malloc(sizeof(**matrix) * (size));
		stack_ptrs[i] = malloc(sizeof(**stack_ptrs) * (size));
		ft_bzero(matrix[i], sizeof(**matrix) * (size));
		ft_bzero(stack_ptrs[i], sizeof(**stack_ptrs) * (size));
		i++;
	}
	(*matrix_address) = matrix;
	(*stack_ptrs_addr) = stack_ptrs;
	stack_ptrs[i] = NULL;
	matrix[i] = NULL;
}

void	free_matrix(int **matrix, t_node ***stack_ptrs, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		free(stack_ptrs[i]);
		free(matrix[i]);
		i++;
	}
	free(stack_ptrs);
	free(matrix);
}
