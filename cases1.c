/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 21:54:51 by ocarlos-          #+#    #+#             */
/*   Updated: 2021/09/01 23:19:29 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

//CASES USED IN FLOW1.C
int		ft_flowcase1(t_stacks *data)
{
	if (ft_ready(data))
		return (TRUE);
	if (ft_singlemove1(data))
		return (TRUE);
	if (data->a_heigth == 5)
		ft_pushlowest1(data);
	ft_pushlowest1(data);
	ft_stack_mid(data);
	if (SB[0] > SB[1] && data->a_heigth == 5)
		ft_sb(data, TRUE);
	return (FALSE);
}

void	ft_pushlowest1(t_stacks *data)
{
	int position;
	int lowest;

	lowest = SA[0];
	data->c = 0;
	position = 0;
	while (data->c < data->a_heigth)
	{
		if (SA[data->c] < lowest)
		{
			lowest = SA[data->c];
			position = data->c;
		}
		data->c++;
	}
	if (position < data->a_heigth / 2)
		while (SA[0] != lowest)
			ft_ra(data, TRUE);
	else
		while (SA[0] != lowest)
			ft_rra(data, TRUE);
	ft_pb(data, TRUE);
}