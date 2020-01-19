/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 14:54:47 by kmira             #+#    #+#             */
/*   Updated: 2020/01/18 16:21:01 by kmira            ###   ########.fr       */
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
