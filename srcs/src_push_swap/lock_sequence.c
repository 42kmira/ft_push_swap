/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lock_sequence.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 18:57:44 by kmira             #+#    #+#             */
/*   Updated: 2020/01/28 04:33:09 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** The paramaters for this are a bit wild but it should be done like that.
** The first is the address of a 2D array. Hence the three stars.
** The second is the address of a 2D of pointers:
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

void	print_matrix(int size, t_node *iter, int **matrix)
{
	int	row;
	int	col;

	row = 0;
	while (row < size)
	{
		printf("%3d ", iter->value);
		iter = iter->next;
		row++;
	}
	printf("\n");
	row = 0;
	while (row < size)
	{
		col = 0;
		while (col < size)
		{
			printf("%3d ", matrix[row][col]);
			col++;
		}
		printf("\n");
		row++;
	}
}

void	print_stack_matrix(int size, t_node *iter, t_node ***stack_ptrs)
{
	int	col;
	int	row;

	col = 0;
	while (col < size)
	{
		printf("%3d ", iter->value);
		iter = iter->next;
		col++;
	}
	printf("\n");
	row = 0;
	while (row < size)
	{
		col = -1;
		while (++col < size)
			if (stack_ptrs[row][col] != NULL)
				printf("%3d ", (stack_ptrs[row][col])->value);
			else
				printf("NUL ");
		printf("\n");
		row++;
	}
}

void	find_best_lock_sequence(t_stack *stack, int size)
{
	int		col;
	int		row;
	int		**matrix;
	t_node	***stack_ptrs;
	t_node	*iter;
	t_node	*curr;
	int		best_match;
	int		best_row;
	int		best_col;

	init_matrix(&matrix, &stack_ptrs, size);

	int		i;

	col = 0;
	best_match = 0;
	curr = stack->head;
	while (col < size)
	{
		row = 0;
		while (row < col)
		{
			//what is matrix[row][col]?
			i = 0;
			iter = stack->head;
			while (i < row)
			{
				iter = iter->next;
				i++;
			}
			while (i < col)
			{
				if (iter->value < curr->value && matrix[row][col] <= matrix[row][i])
				{
					stack_ptrs[row][col] = iter;
					matrix[row][col] = matrix[row][i] + 1;
				}
				if (best_match < matrix[row][col])
				{
					best_row = row;
					best_col = col;
					best_match = matrix[row][col];
				}
				iter = iter->next;
				i++;
			}
			row++;
		}
		curr = curr->next;
		col++;
	}

	col = 0;
	iter = stack->head;
	while (col < best_col)
	{
		iter = iter->next;
		col++;
	}
	iter->locked = LOCKED_NODE;
	int	max;
	int	curr_max;

	curr = iter;
	while (col > 0)
	{
		max = matrix[0][col];
		curr_max = max;
		if (curr != NULL && curr->value == iter->value)
		{
			row = 0;
			while (row < col)
			{
				if (matrix[row][col] >= max)
				{
					curr = stack_ptrs[row][col];
					max = curr_max;
				}
				row++;
			}
			if (curr != NULL)
				curr->locked = LOCKED_NODE;
		}
		iter = iter->prev;
		col--;
	}
	// print_matrix(size, stack->head, matrix);
	// printf("\n");
	// print_stack_matrix(size, stack->head, stack_ptrs);
}
