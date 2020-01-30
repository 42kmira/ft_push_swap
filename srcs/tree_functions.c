/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 14:54:47 by kmira             #+#    #+#             */
/*   Updated: 2020/01/30 01:56:47 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The following functions serve two purposes in this project:
** the first is
*/

#include "common.h"

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

t_binary_tree	*init_binary_node(int value)
{
	t_binary_tree	*node;

	node = malloc(sizeof(*node));
	node->left = NULL;
	node->right = NULL;
	node->value = value;
	node->rank = -1;
	return (node);
}

void	tree_insert(t_binary_tree *root, int value)
{
	if (value == root->value)
	{
		errno = EINVAL;
		return ;
	}
	else if (value < root->value)
	{
		if (root->left == NULL)
			root->left = init_binary_node(value);
		else
			tree_insert(root->left, value);
	}
	else if (value > root->value)
	{
		if (root->right == NULL)
			root->right = init_binary_node(value);
		else
			tree_insert(root->right, value);
	}

}

void	count_elems(t_binary_tree *root, int *count)
{
	if (root == NULL)
		return ;
	if (root->left != NULL)
		count_elems(root->left, count);
	*count = *count + 1;
	if (root->right != NULL)
		count_elems(root->right, count);
}

void	fill_array_with_tree(t_binary_tree *root, int *array, int *count)
{
	if (root == NULL)
		return ;
	if (root->left != NULL)
		fill_array_with_tree(root->left, array, count);
	array[*count] = root->value;
	root->rank = *count + 1;
	*count = *count + 1;
	if (root->right != NULL)
		fill_array_with_tree(root->right, array, count);
}

int		tree_to_array(t_binary_tree *root, int **array)
{
	int	size;
	int	i;

	size = 0;
	count_elems(root, &size);
	*array = malloc(sizeof(**array) * (size + 1));
	i = 0;
	fill_array_with_tree(root, *array, &i);
	return (size);
}

t_binary_tree	*get_binarytree_node(t_node *key, t_binary_tree *root)
{
	if (key->value == root->value)
		return (root);
	if (key->value < root->value)
		return (get_binarytree_node(key, root->left));
	else
		return (get_binarytree_node(key, root->right));
}

void	init_rank(t_stack *stack_a, t_binary_tree *root)
{
	t_node			*iter;
	t_node			*start;
	t_binary_tree	*rank_info;

	start = stack_a->head;
	iter = start;
	rank_info = get_binarytree_node(iter, root);
	iter->rank = rank_info->rank;
	iter = iter->next;
	while (iter != start)
	{
		rank_info = get_binarytree_node(iter, root);
		iter->rank = rank_info->rank;
		iter = iter->next;
	}
}
