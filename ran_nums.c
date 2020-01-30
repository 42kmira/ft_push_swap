/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ran_nums.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 16:26:08 by kmira             #+#    #+#             */
/*   Updated: 2020/01/29 23:51:26 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
** Make a sorted list first then randomly generate the location.
** for the location you can keep skipping values until you find an
** empty bucket. This would avoid you from having to check if the
** number is unique and continue rerolling until you find a unique
** number.
*/

#define EMPTY -1

int		*make_random_list(int size)
{
	int		i;
	int		j;
	int		rand_loc;
	int		*sorted;
	int		*result;

	i = 0;
	result = malloc(sizeof(*result) * (size + 1));
	sorted = malloc(sizeof(*sorted) * (size + 1));
	while (i < size)
	{
		sorted[i] = i + 1;
		result[i] = EMPTY;
		i++;
	}

	i = 0;
	while (i < size)
	{
		j = 0;
		rand_loc = rand() % size;
		while (result[rand_loc + j] != EMPTY)
		{
			j++;
			if (rand_loc + j == size)
			{
				j = 0;
				rand_loc = 0;
			}
		}
		result[rand_loc + j] = sorted[i];
		i++;
	}
	return (result);
}

void	print_out_list(int size)
{
	int	i;
	int	*result;

	i = 0;
	result = make_random_list(size);
	while (i < size)
	{
		printf("%d ", result[i]);
		i++;
	}
	printf("\n");
}

int		main(int aa, char **args)
{
	int	i;
	int	size;

	// char *tree_size = malloc(5500 * 11 * (500 * 4));

	// if (tree_size == NULL)
		// printf("ENOMEM\n");
	srand(time(NULL));
	if (aa == 2)
	{
		i = 0;
		size = atoi(args[1]);
		while (i < 1)
		{
			print_out_list(size);
			i++;
		}
	}
	else
		printf("Wrong number of arguements\n");
	return (0);
}


