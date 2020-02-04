/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 17:03:25 by xinu              #+#    #+#             */
/*   Updated: 2020/02/03 22:43:30 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

void	print_detailed(t_node **iter)
{
	t_node *node;

	node = *iter;
	if (*iter == NULL)
	{
		printf("NODE: NULL           ");
		return ;
	}
	if (node->locked == LOCKED_NODE)
		printf("NODE: "GREEN"%-10d %-3d "COLOR_RESET, node->value, node->rank);
	else
		printf("NODE: "CYAN"%-10d %-3d "COLOR_RESET, node->value, node->rank);
	*iter = (*iter)->next;
}

void	print_stacks_detail(t_stack *stack_a, t_stack *stack_b)
{
	t_node *start_a;
	t_node *start_b;
	t_node *iter_a;
	t_node *iter_b;

	start_a = (stack_a->head != NULL) ? stack_a->head : NULL;
	start_b = (stack_b->head != NULL) ? stack_b->head : NULL;
	iter_a = start_a;
	iter_b = start_b;
	printf(MAGENTA"NEW STACK PRINT\n"COLOR_RESET);
	print_detailed(&iter_a);
	print_detailed(&iter_b);
	printf("\n");
	while (iter_a != start_a || iter_b != start_b)
	{
		if (iter_a == start_a)
			printf("NODE: NULL           ");
		else
			print_detailed(&iter_a);
		if (iter_b == start_b)
			printf("NODE: NULL         ");
		else
			print_detailed(&iter_b);
		printf("\n");
	}
}

void	print_tree(t_binary_tree *root)
{
	if (root == NULL)
		return ;
	if (root->left != NULL)
		print_tree(root->left);
	printf("%d ", root->value);
	if (root->right != NULL)
		print_tree(root->right);
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
