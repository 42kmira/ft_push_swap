/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 18:30:47 by kmira             #+#    #+#             */
/*   Updated: 2020/02/01 17:19:21 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	traverse_both_structures(t_node **stack_node,
								t_binary_tree **root, int *status)
{
	if (*status == STACK_NOT_SORTED)
		return ;
	else
	{
		if ((*root)->left != NULL)
			traverse_both_structures(stack_node, &((*root)->left), status);
		if ((*stack_node)->value != (*root)->value)
		{
			*status = STACK_NOT_SORTED;
			return ;
		}
		else
			*stack_node = (*stack_node)->next;
		if ((*root)->right != NULL)
			traverse_both_structures(stack_node, &((*root)->right), status);
	}
}

int		cmp_stack_to_sorted_tree(t_stack *stack_a, t_binary_tree *root)
{
	int				result;
	t_node			*stack_node;
	t_binary_tree	*tree;

	result = STACK_SORTED;
	stack_node = stack_a->head;
	tree = root;
	traverse_both_structures(&stack_node, &tree, &result);
	return (result);
}
