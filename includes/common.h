/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 16:48:07 by marvin            #+#    #+#             */
/*   Updated: 2020/02/06 08:48:23 by kmira            ###   ########.fr       */
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

# define STACK_SORTED 1
# define STACK_NOT_SORTED -1

# define LOCKED_NODE 1
# define UNLOCKED_NODE 0

enum	e_move_operations
{
	ADD,
	SUBTRACT,
	READ
};

char			is_only_node(t_node *node);
char			is_only_two_nodes(t_node *first, t_node *second);
int				count_nodes(t_stack *stack);

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** FILE: move_interface.c
** Description: interface with changing how many moves have been done.
*/

int				add_move_counter(void);
int				subtract_move_counter(void);
int				counter_interface(int operation, int value);

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** FILE: stack_ops.c
** Description: Handles the stack.
*/

t_stack			*init_stack(void);
t_node			*pop(t_stack *stack);
void			insert_by_value(t_stack *stack, int value);
void			insert_by_node(t_stack *stack, t_node *elem);
void			free_stack(t_stack *stack);

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** FILE: input_to_stack.c
** Description: Transform program agruements into a stack_a.
*/

t_stack			*create_stack_a(char **args, t_binary_tree **root, int aa);
void			print_tree(t_binary_tree *root);
t_binary_tree	*init_binary_node(int value);
void			tree_insert(t_binary_tree *root, int value);
int				cmp_stack_to_sorted_tree(t_stack *stack_a, t_binary_tree *root);
int				tree_to_array(t_binary_tree *root, int **array);
void			fill_array_with_tree(t_binary_tree *root, int *arr, int *count);
void			init_rank(t_stack *stack_a, t_binary_tree *root);
void			free_tree(t_binary_tree *root);

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** FILE: operations.c
** Description: Move set for the list.
*/

void			sa(t_stack *stack_a, t_stack *stack_b);
void			sb(t_stack *stack_a, t_stack *stack_b);
void			ss(t_stack *stack_a, t_stack *stack_b);
void			pa(t_stack *stack_a, t_stack *stack_b);
void			pb(t_stack *stack_a, t_stack *stack_b);
void			ra(t_stack *stack_a, t_stack *stack_b);
void			rb(t_stack *stack_a, t_stack *stack_b);
void			rr(t_stack *stack_a, t_stack *stack_b);
void			rra(t_stack *stack_a, t_stack *stack_b);
void			rrb(t_stack *stack_a, t_stack *stack_b);
void			rrr(t_stack *stack_a, t_stack *stack_b);

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** FILE: buffer.c
** Description: Prints out things in a buffer.
*/

void			buffer_output_str(char *str, int final);
void			flush_buffer_str(void);

#endif
