/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 16:41:24 by marvin            #+#    #+#             */
/*   Updated: 2020/02/05 05:21:44 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdio.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

# include "common.h"

# define OPS_READ_BUFFER 300
# define EMPTY_ARGS 2

typedef struct	s_operation
{
	void	(*operation)(t_stack *, t_stack *);
	char	op_name[5];
}				t_operation;

void			get_user_input(t_stack *stack_a, t_stack *stack_b);

#endif
