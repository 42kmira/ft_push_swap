/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 16:48:07 by marvin            #+#    #+#             */
/*   Updated: 2020/01/22 23:34:55 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** HEADERS
*/

# include <stddef.h>
# include <stdlib.h>
# include <stdint.h>
# include <errno.h>

# include "common_struct.h"
# include "color.h"
# include "libft.h"
# include "debug.h"

enum	move_operations
{
	ADD,
	SUBTRACT,
	READ
};

void	comm_test(char *str);
char	is_only_node(t_node *node);

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** FILE: move_interface.c
** Description: interface with changing how many moves have been done.
*/

int	add_move_counter(void);
int	subtract_move_counter(void);

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** FILE: stack_ops.c
** Description: Handles the stack.
*/

t_stack		*init_stack(void);
t_node		*pop(t_stack *stack);
void		insert_by_value(t_stack *stack, int value);
void		insert_by_node(t_stack *stack, t_node *elem);

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** FILE: input_to_stack.c
** Description: Transform program agruements into a stack_a.
*/

t_stack			*create_stack_from_list(char **args, t_binary_tree **root);
void			print_tree(t_binary_tree *root);
t_binary_tree	*init_binary_node(int value);
void			tree_insert(t_binary_tree *root, int value);
int				cmp_stack_to_sorted_tree(t_stack *stack_a, t_binary_tree *root);
int				tree_to_array(t_binary_tree *root, int **array);
void			fill_array_with_tree(t_binary_tree *root, int *array, int *count);

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** FILE: operations.c
** Description: Move set for the list.
*/

void	sa(t_stack *stack_a, t_stack *stack_b);
void	sb(t_stack *stack_a, t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);
void	ra(t_stack *stack_a, t_stack *stack_b);
void	rb(t_stack *stack_a, t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rra(t_stack *stack_a, t_stack *stack_b);
void	rrb(t_stack *stack_a, t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);

#endif
