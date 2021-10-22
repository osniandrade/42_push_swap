/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flow1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 09:13:38 by ocarlos-          #+#    #+#             */
/*   Updated: 2021/10/22 21:04:23 by ocarlos-         ###   ########.fr       */
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
	t_lowest	up;
	t_lowest	down;
	int			i;
	int			c;

	if (ft_singlemove1(data))
		return ;
	if (ft_singlemove2(data))
		return ;
	
	while (data->b_heigth != 0)
		ft_pa(data, TRUE);
}

// finds the smallest 2 values from top and bottom
t_lowest	ft_twosmall(t_stacks *data)
{
	int	i;
	int	c;
	t_lowest	nt;
	t_lowest	nb;

	while (data->a_heigth != 1)
	{
		i = 0;
		c = 0;
		while (i < data->a_heigth)
		{
			if (SA[i] == LIST[c] || SA[i] == LIST[c + 1])
			{
				nt.lowest = SA[i];
				nt.position = i;
			}
			i++;
		}
		while (i != 0)
		{
			if (SA[i] == LIST[c] || SA[i] == LIST[c + 1])
			{
				nb.lowest = SA[i];
				nb.position = i;
			}
			i--;
		}
		//if (nt)
	}
}
