/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 11:21:57 by kmira             #+#    #+#             */
/*   Updated: 2019/12/05 12:29:39 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_STRUCT_H
# define COMMON_STRUCT_H

typedef	struct		s_node
{
	int				value;
	struct	s_node	*next;
}					t_node;

typedef	struct		s_stack
{
	struct	s_node	*top;
	int				count;
}					t_stack;

#endif

