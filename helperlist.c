/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helperlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 13:35:34 by ocarlos-          #+#    #+#             */
/*   Updated: 2021/10/27 22:42:41 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// normalizes the numbers in SA to simpler positive numbers
void	ft_normalize(t_stacks *data)
{
	t_lowest	p;
	
	p.c = 0;
	p.last = __INT_MAX__ * -1;
	while (p.c < data->a_heigth)
	{
		p.i = 0;
		p.p = 0;
		p.lowest = __INT_MAX__;
		while (p.i < data->a_heigth)
		{
			if (SA[p.i] < p.lowest && SA[p.i] > p.last )
			{
				p.lowest = SA[p.i];
				p.p = p.i;
			}
			p.i++;
		}
		LIST[p.p] = p.c;
		p.last = p.lowest;
		p.c++;
	}
}

// swaps numbers between SA to LIST
void	ft_sortlist(t_stacks *data)
{
	int	i;
	int	temp;

	i = 1;
	while (i < data->a_heigth)
	{
		if (LIST[i - 1] > LIST[i])
		{
			temp = LIST[i - 1];
			LIST[i - 1] = LIST[i];
			LIST[i] = temp;
			i = 1;
		}
		else
			i++;
	}
}

// sorts numbers in LIST
void	ft_movelist(t_stacks *data)
{
	int	c;
	int	temp;

	c = data->a_heigth;
	while (c > 0)
	{
		c--;
		temp = LIST[c];
		LIST[c] = SA[c];
		SA[c] = temp;
	}
}

// loads SA in a secondary list and sorts it
void	ft_helperlist(t_stacks *data)
{
	ft_normalize(data);
	ft_movelist(data);
	ft_sortlist(data);
}
