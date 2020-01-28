/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 00:34:10 by kmira             #+#    #+#             */
/*   Updated: 2020/01/28 04:34:32 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <common.h>

char *fetch_command_sequence(int *rank_order)
{
	if (rank_order[0] == LOW && rank_order[1] == MED)
		return ("ra ra ra");
	else if (rank_order[0] == LOW && rank_order[1] == HIG)
		return ("ra sa ra ra");
	else if (rank_order[0] == MED && rank_order[1] == LOW)
		return ("sa ra ra ra");
	else if (rank_order[0] == MED && rank_order[1] == HIG)
		return ("pb sa ra pa ra ra");
	else if (rank_order[0] == HIG && rank_order[1] == LOW)
		return ("sa ra sa ra ra");
	else if (rank_order[0] == HIG && rank_order[1] == MED)
		return ("pb sa ra ra pa ra");
	else
		return (NULL);
}

/*
** If the number is equal to or less than all the numbers it is
** the lowest of the three.
** If the number if equal to or grater than all the numbers it is
** the highest of the three.
** If the number is not the highest or the lowest it must be the
** middle value.
*/

int		rank_of_three(int num1, int num2, int num3, int check)
{
	int result;

	if (check <= num1 && check <= num2 && check <= num3)
		result = LOW;
	else if (check >= num1 && check >= num2 && check >= num3)
		result = HIG;
	else
		result = MED;
	return (result);
}

void	local_rank_three(t_stack *stack_a)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	first = stack_a->head;
	second = first->next;
	third = second->next;

	first->local_rank = rank_of_three(first->rank, second->rank, third->rank, first->rank);
	second->local_rank = rank_of_three(first->rank, second->rank, third->rank, second->rank);
	third->local_rank = rank_of_three(first->rank, second->rank, third->rank, third->rank);
}

void	do_commands(char *str, t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i + 0] == 'r' && str[i + 1] == 'a')
			ra(stack_a, stack_b);
		else if (str[i + 0] == 's' && str[i + 1] == 'a')
			sa(stack_a, stack_b);
		else if (str[i + 0] == 'p' && str[i + 1] == 'b')
			pb(stack_a, stack_b);
		else if (str[i + 0] == 'p' && str[i + 1] == 'a')
			pa(stack_a, stack_b);
		else
			printf("Error parsing the command string\n");
		i++;
		i++;
		if (str[i] == ' ')
			i++;
	}
}

void	sort_by_group_of_three(t_stack *stack_a, t_stack *stack_b)
{
	char	*commands;
	int		order[2];

	local_rank_three(stack_a);
	order[0] = (stack_a->head)->local_rank;
	order[1] = ((stack_a->head)->next)->local_rank;
	commands = fetch_command_sequence(order);

	// printf("Commands to do %s\n", commands);
	do_commands(commands, stack_a, stack_b);
}

void	sort_entire_stack_by_groups_of_three(t_stack *stack_a, t_stack *stack_b, int size)
{
	int	i;

	i = 0;
	while (i < size / 3)
	{
		sort_by_group_of_three(stack_a, stack_b);
		i++;
	}
	i = 0;
	while (i < size % 3)
	{
		ra(stack_a, stack_b);
		i++;
	}
}
