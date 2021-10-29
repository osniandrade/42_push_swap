/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 12:32:32 by ocarlos-          #+#    #+#             */
/*   Updated: 2021/10/29 12:39:44 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// checks if its possible to sort data->la with a single move (ra)
int	ft_singlemove1(t_stks *data)
{
	int	i;

	i = 1;
	if (data->la[0].o > data->la[data->a_heigth - 1].o)
	{
		while (i < data->a_heigth - 1)
		{
			if (data->la[i].o < data->la[i + 1].o)
				i++;
			else
				return (FALSE);
		}
		ft_ra(data, TRUE);
		return (TRUE);
	}
	return (FALSE);
}

// checks if its possible to sort data->la with a single move (rra)
int	ft_singlemove2(t_stks *data)
{
	int	i;

	i = 1;
	if (data->la[0].o > data->la[data->a_heigth - 1].o)
	{
		while (i < data->a_heigth - 1)
		{
			if (data->la[i].o < data->la[i + 1].o)
				i++;
			else
				return (FALSE);
		}
		ft_rra(data, TRUE);
		return (TRUE);
	}
	return (FALSE);
}
