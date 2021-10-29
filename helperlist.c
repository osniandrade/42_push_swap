/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helperlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 13:35:34 by ocarlos-          #+#    #+#             */
/*   Updated: 2021/10/29 13:53:39 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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
		p.lowest = __INT_MAX__;
		while (p.i < data->a_heigth)
		{
			if (data->la[p.i].o < p.lowest && data->la[p.i].o > p.last)
			{
				p.lowest = data->la[p.i].o;
				p.p = p.i;
			}
			p.i++;
		}
		data->la[p.p].n = p.c;
		p.last = p.lowest;
		p.c++;
	}
}

// loads data->la in a secondary list and sorts it
void	ft_helperlist(t_stks *data)
{
	ft_normalize(data);
}
