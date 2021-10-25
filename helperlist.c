/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helperlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 13:35:34 by ocarlos-          #+#    #+#             */
/*   Updated: 2021/10/25 22:44:05 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// loads SA in a secondary list and sorts it
void	ft_helperlist(t_stacks *data)
{
	int	lowest;
	int	last;
	int	i;  // iterations
	int	p;  // position of lowest
	int	c;  // count of numbers normalized

	c = 0;
	last = __INT_MAX__ * -1;
	while (c < data->a_heigth)
	{
		i = 0;
		p = 0;
		lowest = __INT_MAX__;
		while (i < data->a_heigth)
		{
			if (SA[i] < lowest && SA[i] > last )
			{
				lowest = SA[i];
				p = i;
			}
			i++;
		}
		LIST[p] = c + 1;
		last = lowest;
		c++;
	}
	//TODO: move all numbers from LIST to SA and sort LIST
}
