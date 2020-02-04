/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 07:41:29 by kmira             #+#    #+#             */
/*   Updated: 2020/02/03 00:43:39 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

t_binary_tree	*get_binarytree_node(t_node *key, t_binary_tree *root)
{
	if (key->value == root->value)
		return (root);
	if (key->value < root->value)
		return (get_binarytree_node(key, root->left));
	else
		return (get_binarytree_node(key, root->right));
}

void			count_elems(t_binary_tree *root, int *count)
{
	if (root == NULL)
		return ;
	if (root->left != NULL)
		count_elems(root->left, count);
	*count = *count + 1;
	if (root->right != NULL)
		count_elems(root->right, count);
}

void			fill_array_with_tree(t_binary_tree *root, int *arr, int *count)
{
	if (root == NULL)
		return ;
	if (root->left != NULL)
		fill_array_with_tree(root->left, arr, count);
	arr[*count] = root->value;
	root->rank = *count + 1;
	*count = *count + 1;
	if (root->right != NULL)
		fill_array_with_tree(root->right, arr, count);
}

int				tree_to_array(t_binary_tree *root, int **array)
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

void			init_rank(t_stack *stack_a, t_binary_tree *root)
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
