/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flow1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 09:13:38 by ocarlos-          #+#    #+#             */
/*   Updated: 2021/06/01 15:18:02 by ocarlos-         ###   ########.fr       */
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
	if (data->a_heigth == 5)
		ft_pb(data, TRUE);
	ft_pb(data, TRUE);
	ft_stack_mid(data);
	if (SB[0] > SB[1])
		ft_sb(data, TRUE);
	while (data->b_heigth > 0)
	{
		if (SB[0] < SA[0])
			ft_pa(data, TRUE);
		if (SA[0] < SB[0] && SA[1] > SB[0])
		{
			ft_ra(data, TRUE);
			ft_pa(data, TRUE);
			r++;
		}
		else if ((data->b_heigth == 1 && r == (data->max_heigth - 1)) ||
				data->a_heigth == r)
		{
			ft_pa(data, TRUE);
			ft_ra(data, TRUE);
			if (data->a_heigth == data->max_heigth)
				return ;
			r++;
		}
		else
		{
			ft_ra(data, TRUE);
			r++;
		}
	}
	while (r > 0)
	{
		ft_rra(data, TRUE);
		r--;
	}
}

// stack size > 5
void	ft_stack_huge(t_stacks *data)
{
	data->c++;
	return ;
}