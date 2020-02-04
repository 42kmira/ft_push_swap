/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lock_sequence.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 18:57:44 by kmira             #+#    #+#             */
/*   Updated: 2020/02/03 22:45:41 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		highest_col(int **matrix, int size)
{
	int	row;
	int	col;
	int	best_chain;
	int	result;

	row = 0;
	best_chain = 0;
	result = 0;
	while (row < size)
	{
		col = 0;
		while (col < size)
		{
			if (best_chain < matrix[row][col])
			{
				best_chain = matrix[row][col];
				result = col;
			}
			col++;
		}
		row++;
	}
	return (result);
}

int		scan_rows_for_max_chain(int **matrix, t_node ***stack_ptrs,
								int stop, t_node **cur)
{
	int	row;
	int	max_result;

	row = 0;
	max_result = matrix[0][stop];
	while (row < stop)
	{
		if (matrix[row][stop] >= max_result)
		{
			*cur = stack_ptrs[row][stop];
			max_result = matrix[row][stop];
		}
		row++;
	}
	return (max_result);
}

void	lock_nodes(int **matrix, t_node ***stack_ptrs,
						t_stack *stack, int size)
{
	int			max;
	int			col;
	int			best_col;
	t_node		*curr;
	t_node		*iter;

	col = -1;
	iter = stack->head;
	best_col = highest_col(matrix, size);
	while (++col < best_col)
		iter = iter->next;
	iter->locked = LOCKED_NODE;
	curr = iter;
	while (col > 0)
	{
		if (curr != NULL && curr == iter)
		{
			max = scan_rows_for_max_chain(matrix, stack_ptrs, col, &curr);
			if (curr != NULL)
				curr->locked = LOCKED_NODE;
		}
		iter = iter->prev;
		col--;
	}
}

void	fill_matrix(int **matrix, t_node ***stack_ptrs, int col, t_stack *stack)
{
	int		i;
	int		row;
	t_node	*iter;
	t_node	*curr;

	i = -1;
	row = -1;
	curr = stack->head;
	while (++i < col)
		curr = curr->next;
	while (++row < col)
	{
		i = -1;
		iter = stack->head;
		while (++i < col)
		{
			if (i > row && iter->value < curr->value
				&& matrix[row][col] <= matrix[row][i])
			{
				stack_ptrs[row][col] = iter;
				matrix[row][col] = matrix[row][i] + 1;
			}
			iter = iter->next;
		}
	}
}

void	find_best_lock_sequence(t_stack *stack, int size)
{
	int		col;
	int		**matrix;
	t_node	***stack_ptrs;

	col = 0;
	init_matrix(&matrix, &stack_ptrs, size);
	while (col < size)
	{
		fill_matrix(matrix, stack_ptrs, col, stack);
		col++;
	}
	lock_nodes(matrix, stack_ptrs, stack, size);
	free_matrix(matrix, stack_ptrs, size);
}
