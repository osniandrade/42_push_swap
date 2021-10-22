/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 13:35:34 by ocarlos-          #+#    #+#             */
/*   Updated: 2021/10/22 19:32:20 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_helperlist(t_stacks *data)
{
	int		c;
	int		temp;

	c = 0;
	while (c < data->a_heigth - 1)
	{
		if (data->list[c] > data->list[c + 1])
		{
			temp = data->list[c];
			data->list[c] = data->list[c + 1];
			data->list[c + 1] = temp;
			c = 0;
		}
		else
			c++;
	}
}
