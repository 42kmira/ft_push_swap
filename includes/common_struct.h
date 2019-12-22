/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinu <xinu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 11:21:57 by kmira             #+#    #+#             */
/*   Updated: 2019/12/21 20:28:38 by xinu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_STRUCT_H
# define COMMON_STRUCT_H

typedef	struct		s_node
{
	int				value;
	struct	s_node	*next;
	// struct	s_node	*prev;
}					t_node;

typedef	struct		s_stack
{
	struct	s_node	*top;
	struct	s_node	*last;
	int				count;
}					t_stack;

#endif
