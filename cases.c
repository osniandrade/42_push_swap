/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 21:54:51 by ocarlos-          #+#    #+#             */
/*   Updated: 2021/10/29 12:53:24 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// sorts 4 to 5 numbers in data->la
int	ft_flowcase1(t_stks *data)
{
	if (ft_singlemove1(data))
		return (TRUE);
	if (ft_singlemove2(data))
		return (TRUE);
	if (data->a_heigth == 5)
		ft_pushlowest(data);
	ft_pushlowest(data);
	ft_stack_mid(data);
	if (data->lb[0].o > data->lb[1].o && data->a_heigth == 5)
		ft_sb(data, TRUE);
	return (FALSE);
}

// finds the lowest number in data->la
t_var	ft_findlowest(t_stks *data)
{
	int		i;
	t_var	l;

	i = 0;
	l.max = data->la[0].o;
	while (i < data->a_heigth)
	{
		if (data->la[i].o < l.max)
		{
			l.max = data->la[i].o;
		}
		i++;
	}
	return (l);
}

// rolls data->la as little as possible and pushes its lowest value to data->lb
void	ft_pushlowest(t_stks *data)
{
	t_var	l;

	l = ft_findlowest(data);
	if (l.p < data->a_heigth / 2)
		while (data->la[0].o != l.max)
			ft_ra(data, TRUE);
	else
		while (data->la[0].o != l.max)
			ft_rra(data, TRUE);
	if (ft_ready(data))
		ft_exit(data);
	ft_pb(data, TRUE);
}

// sort more than 5 numbers using RADIX algorithm and bitwise
void	ft_sorthuge(t_stks *data)
{
	int		h_num;
	int		m_bit;
	t_var	n;

	n = (t_var){0};
	h_num = data->a_heigth - 1;
	m_bit = 0;
	while ((h_num >> m_bit) != 0)
		m_bit++;
	while (n.i < m_bit)
	{
		while (n.p < data->max_heigth)
		{
			if ((data->la[0].n >> n.i) & 1 == 1)
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
