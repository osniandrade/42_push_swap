/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flow1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 09:13:38 by ocarlos-          #+#    #+#             */
/*   Updated: 2021/09/09 23:38:28 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// stack size = 2
void	ft_stack_small(t_stacks *data)
{
	if (SA[0] > SA[1])
		ft_sa(data, TRUE);
}

// stack size = 3
void	ft_stack_mid(t_stacks *data)
{
	if (SA[1] < SA[0] && SA[0] < SA[2])
		ft_sa(data, TRUE);
	else if (SA[2] < SA[1] && SA[1] < SA[0])
	{
		ft_sa(data, TRUE);
		ft_rra(data, TRUE);
	}
	else if (SA[1] < SA[2] && SA[2] < SA[0])
		ft_ra(data, TRUE);
	else if (SA[0] < SA[2] && SA[2] < SA[1])
	{
		ft_sa(data, TRUE);
		ft_ra(data, TRUE);
	}
	else if (SA[2] < SA[1] && SA[0] < SA[1])
		ft_rra(data, TRUE);
}

// stack size = 4 or 5
void	ft_stack_big(t_stacks *data)
{
	int	r;

	r = 0;
	if(ft_flowcase1(data))
		return ;
	if(data->a_heigth == 3)
		ft_pa(data, TRUE);
	ft_pa(data, TRUE);
}

// stack size > 5
void	ft_stack_huge(t_stacks *data)
{
	int		c_list;
	int		c_a;
	int		c_b;
	
	c_list = 0;
	if (ft_singlemove1(data))
		return ;
	if (ft_singlemove2(data))
		return ;
	while (!ft_ready(data))
	{
		c_a = 0;
		c_b = data->a_heigth;
		while (SA[c_a] != data->list[c_list] && SA[c_a] != data->list[c_list + 1])
			c_a++;
		while (SB[c_b] != data->list[data->a_heigth - c_list] &&
				SB[c_b] != data->list[data->a_heigth - c_list - 1])
			c_b--;
		c_b = data->a_heigth - c_b;
		if (c_a >= c_b)
			while (c_a-- != 0)
				ft_ra(data, TRUE);
		else
			while (c_b-- != 0)
				ft_rra(data, TRUE);
		if (data->a_heigth > 1)
			ft_pb(data, TRUE);
		if (data->b_heigth > 1 && SB[0] > SB[1])
			ft_sb(data, TRUE);
		c_list++;
		if (data->a_heigth == 1)
			while (data->b_heigth != 0)
				ft_pa(data, TRUE);
	}
	
}
