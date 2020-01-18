/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 11:21:57 by kmira             #+#    #+#             */
/*   Updated: 2020/01/18 14:59:57 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_STRUCT_H
# define COMMON_STRUCT_H

typedef	struct		s_node
{
	int				value;
	struct	s_node	*next;
	struct	s_node	*prev;
}					t_node;

typedef	struct		s_stack
{
	struct	s_node	*head;
	int				count;
}					t_stack;

typedef struct	s_binary_tree
{
	int						value;
	struct t_binary_tree	*left;
	struct t_binary_tree	*right;
}				t_binary_tree;

#endif

