/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 21:54:51 by ocarlos-          #+#    #+#             */
/*   Updated: 2021/10/27 22:37:56 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// sorts 4 to 5 numbers in SA
int			ft_flowcase1(t_stacks *data)
{
	if (ft_singlemove1(data))
		return (TRUE);
	if (ft_singlemove2(data))
		return (TRUE);
	if (data->a_heigth == 5)
		ft_pushlowest(data);
	ft_pushlowest(data);
	ft_stack_mid(data);
	if (SB[0] > SB[1] && data->a_heigth == 5)
		ft_sb(data, TRUE);
	return (FALSE);
}

// finds the lowest number in SA
t_lowest	ft_findlowest(t_stacks *data)
{
	int			i;
	t_lowest	l;

	i = 0;
	l.lowest = SA[0];
	while (i < data->a_heigth)
	{
		if (SA[i] < l.lowest)
		{
			l.lowest = SA[i];
			l.p = i;
		}
		i++;
	}
	return (l);
}

// rolls SA as little as possible and pushes its lowest value to SB
void		ft_pushlowest(t_stacks *data)
{
	t_lowest	l;

	l = ft_findlowest(data);
	if (l.p < data->a_heigth / 2)
		while (SA[0] != l.lowest)
			ft_ra(data, TRUE);
	else
		while (SA[0] != l.lowest)
			ft_rra(data, TRUE);
	if (ft_ready(data))
		ft_exit(data);
	ft_pb(data, TRUE);
}

// sort more than 5 numbers using RADIX algorithm and bitwise
void		ft_sorthuge(t_stacks *data)
{
	int	h_num;
	int	m_bit;
	t_lowest n;

	n = (t_lowest){0};
	h_num = data->a_heigth - 1;
	m_bit = 0;
	while ((h_num >> m_bit) != 0)
		m_bit++;
	while (n.i < m_bit)
	{
		while (n.p < data->max_heigth)
		{
			if ((SA[0] >> n.i)&1 == 1)
				ft_ra(data, TRUE);
			else
				ft_pb(data, TRUE);
			n.p++;
		}
		while (data->b_heigth != 0)
			ft_pa(data, TRUE);
		n.p = 0;
		n.i++;
	}
}
