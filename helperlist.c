/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helperlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 13:35:34 by ocarlos-          #+#    #+#             */
/*   Updated: 2021/10/29 17:43:17 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// sets data->la.n to -1 for validating purposes
void	ft_negative(t_stks *data)
{
	int	i;

	i = 0;
	while (i < data->a_heigth)
	{
		data->la[i].n = -1;
		i++;
	}
}

// normalizes the numbers in data->la to simpler positive numbers
void	ft_normalize(t_stks *data)
{
	t_var	p;

	p.c = 0;
	p.last = __INT_MAX__ * -1;
	while (p.c < data->a_heigth)
	{
		p.i = 0;
		p.p = 0;
		p.max = __INT_MAX__;
		while (p.i < data->a_heigth)
		{
			if (data->la[p.i].o <= p.max && data->la[p.i].o > p.last)
			{
				p.max = data->la[p.i].o;
				p.p = p.i;
			}
			p.i++;
		}
		data->la[p.p].n = p.c;
		p.last = p.max;
		p.c++;
	}
}
