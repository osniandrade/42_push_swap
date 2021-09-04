/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 12:32:32 by ocarlos-          #+#    #+#             */
/*   Updated: 2021/09/04 15:07:36 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_singlemove1(t_stacks *data)
{
	data->c = 1;
	if (SA[0] > SA[data->a_heigth - 1])
	{
		while (data->c < data->a_heigth - 1)
		{
			if (SA[data->c] < SA[data->c + 1])
				data->c++;
			else
				return (FALSE);
		}
		ft_ra(data, TRUE);
		return (TRUE);
	}
	return (FALSE);
}

int		ft_singlemove2(t_stacks *data)
{
	data->c = 1;
	if (SA[0] > SA[data->a_heigth - 1])
	{
		while (data->c < data->a_heigth - 2)
		{
			if (SA[data->c] < SA[data->c + 1])
				data->c ++;
			else
				return (FALSE);
		}
		ft_rra(data, TRUE);
		return (TRUE);
	}
	return (FALSE);
}