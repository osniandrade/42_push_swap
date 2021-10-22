/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 12:32:32 by ocarlos-          #+#    #+#             */
/*   Updated: 2021/10/22 19:23:25 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_singlemove1(t_stacks *data)
{
	int	i;

	i = 1;
	if (SA[0] > SA[data->a_heigth - 1])
	{
		while (i < data->a_heigth - 1)
		{
			if (SA[i] < SA[i + 1])
				i++;
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
	int	i;

	i = 1;
	if (SA[0] > SA[data->a_heigth - 1])
	{
		while (i < data->a_heigth - 1)
		{
			if (SA[i] < SA[i + 1])
				i++;
			else
				return (FALSE);
		}
		ft_rra(data, TRUE);
		return (TRUE);
	}
	return (FALSE);
}

int		ft_findmovers(t_stacks *data, int postop, int posbot)
{
	int	i;

	i = 0;
	return (0);
}