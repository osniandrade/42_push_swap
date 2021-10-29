/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 23:28:19 by ocarlos-          #+#    #+#             */
/*   Updated: 2021/10/29 12:39:59 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// prints an error message on the terminal
void	ft_error(t_stks *data, int clean)
{
	ft_putstr_fd("Error\n", 1);
	if (clean)
		ft_exit(data);
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
		{
			if (*argv[c] != '-')
			{
				ft_putstr_fd("Error\n", 1);
				exit(0);
			}
		}
		c++;
	}
	if (argc == 2)
		exit(0);
}

// checks if numbers are valid integers
void	ft_checknumbers(t_stks *data)
{
	int			pivot;
	int			i;
	long int	max;
	long int	min;

	pivot = 0;
	i = 1;
	max = __INT_MAX__;
	min = (__INT_MAX__ * -1) + 1;
	while (pivot < data->a_heigth)
	{
		i = pivot + 1;
		while (i < data->a_heigth)
		{
			if ((data->la[pivot].o == data->la[i].o)
				|| (data->la[pivot].o > max)
				|| (data->la[i].o > max)
				|| (data->la[pivot].o < min)
				|| (data->la[i].o < min))
				ft_error(data, 0);
			i++;
		}
		pivot++;
	}
}

// checks if data->la is already sorted
int	ft_ready(t_stks *data)
{
	int	i;

	if (!data->lb[0].o)
	{
		i = 0;
		while (i < data->a_heigth - 1)
		{
			if (data->la[i].o < data->la[i + 1].o)
				i++;
			else
				return (FALSE);
		}
		return (TRUE);
	}
	return (FALSE);
}
