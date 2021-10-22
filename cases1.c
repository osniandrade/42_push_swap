/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 21:54:51 by ocarlos-          #+#    #+#             */
/*   Updated: 2021/10/22 19:30:21 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

//CASES USED IN FLOW1.C
int		ft_flowcase1(t_stacks *data)
{
	if (ft_singlemove1(data))
		return (TRUE);
	if (ft_singlemove2(data))
		return (TRUE);
	if (data->a_heigth == 5)
		ft_pushlowest1(data);
	ft_pushlowest1(data);
	ft_stack_mid(data);
	if (SB[0] > SB[1] && data->a_heigth == 5)
		ft_sb(data, TRUE);
	return (FALSE);
}

// finds the lowest number in SA, rolls the stack as 
// little as possible and pushes it to SB
void	ft_pushlowest1(t_stacks *data)
{
	int position;
	int lowest;
	int	i;

	lowest = SA[0];
	i = 0;
	position = 0;
	while (i < data->a_heigth)
	{
		if (SA[i] < lowest)
		{
			lowest = SA[i];
			position = i;
		}
		i++;
	}
	if (position < data->a_heigth / 2)
		while (SA[0] != lowest)
			ft_ra(data, TRUE);
	else
		while (SA[0] != lowest)
			ft_rra(data, TRUE);
	if (ft_ready(data))
		ft_exit(data);
	ft_pb(data, TRUE);
}

