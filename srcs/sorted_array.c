/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 07:41:29 by kmira             #+#    #+#             */
/*   Updated: 2020/02/06 09:57:10 by kmira            ###   ########.fr       */
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

void			init_rank_by_recurrsion(t_binary_tree *root, int *count)
{
	if (root == NULL)
		return ;
	if (root->left != NULL)
		init_rank_by_recurrsion(root->left, count);
	root->rank = *count + 1;
	*count = *count + 1;
	if (root->right != NULL)
		init_rank_by_recurrsion(root->right, count);
}

void			init_rank(t_binary_tree *root)
{
	int	i;

	i = 0;
	init_rank_by_recurrsion(root, &i);
}

void			fill_rank(t_stack *stack_a, t_binary_tree *root)
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
