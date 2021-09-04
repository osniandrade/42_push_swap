/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 23:28:19 by ocarlos-          #+#    #+#             */
/*   Updated: 2021/09/04 15:35:38 by ocarlos-         ###   ########.fr       */
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

	pivot = 0;
	data->c = 1;
	while (pivot < data->a_heigth)
	{
		data->c = pivot + 1;
		while (data->c < data->a_heigth)
		{
			if ((SA[pivot] == SA[data->c]) || 
					(SA[pivot] > __INT_MAX__) ||
					(SA[data->c] > __INT_MAX__))
				ft_error();
			data->c++;
		}
		pivot++;
	}
}

int		ft_ready(t_stacks *data)
{
	if (!SB[0])
	{
		data->c = 0;
		while (data->c < data->a_heigth - 1)
		{
			if (SA[data->c] < SA[data->c + 1])
				data->c++;
			else
				return (FALSE);
		}
		return (TRUE);
	}
	return (FALSE);
}

int		ft_sa_in_order(t_stacks *data)
{
	data->c = 0;
	if (data->a_heigth == 1)
		return (TRUE);
	if (data->a_heigth > 1)
	{
		while (data->c < data->a_heigth - 1)
		{
			if (SA[data->c] < SA[data->c + 1])
				data->c++;
			else
				return (FALSE);
		}
		return (TRUE);
	}
	return (FALSE);
}