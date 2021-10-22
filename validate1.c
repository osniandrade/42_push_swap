/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 23:28:19 by ocarlos-          #+#    #+#             */
/*   Updated: 2021/10/22 19:27:33 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_error()
{
	printf("Error\n");
	exit(0);
}

void	ft_checkargs(int argc, char **argv)
{
	int		c;

	c = 1;
	while (c < argc)
	{
		if (!(ft_isdigit(*argv[c])))
			if (*argv[c] != '-')
				ft_error();
		c++;
	}
	if (argc == 2)
		exit(0);
}

void	ft_checknumbers(t_stacks *data)
{
	int		pivot;
	int		i;

	pivot = 0;
	i = 1;
	while (pivot < data->a_heigth)
	{
		i = pivot + 1;
		while (i < data->a_heigth)
		{
			if ((SA[pivot] == SA[i]) || 
					(SA[pivot] > __INT_MAX__) ||
					(SA[i] > __INT_MAX__))
				ft_error();
			i++;
		}
		pivot++;
	}
}

int		ft_ready(t_stacks *data)
{
	int	i;

	if (!SB[0])
	{
		i = 0;
		while (i < data->a_heigth - 1)
		{
			if (SA[i] < SA[i + 1])
				i++;
			else
				return (FALSE);
		}
		return (TRUE);
	}
	return (FALSE);
}
