/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 23:28:19 by ocarlos-          #+#    #+#             */
/*   Updated: 2021/10/28 21:38:34 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// prints an error message on the terminal
void	ft_error()
{
	ft_putstr_fd("Error\n", 1);
	exit(0);
}

// checks if input arguments are present and valid
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

// checks if numbers are valid integers
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
			if ((SA[pivot].o == SA[i].o) || 
					(SA[pivot].o > __INT_MAX__) ||
					(SA[i].o > __INT_MAX__))
				ft_error();
			i++;
		}
		pivot++;
	}
}

// checks if SA is already sorted
int		ft_ready(t_stacks *data)
{
	int	i;

	if (!SB[0].o)
	{
		i = 0;
		while (i < data->a_heigth - 1)
		{
			if (SA[i].o < SA[i + 1].o)
				i++;
			else
				return (FALSE);
		}
		return (TRUE);
	}
	return (FALSE);
}
