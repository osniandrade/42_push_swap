/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 13:35:34 by ocarlos-          #+#    #+#             */
/*   Updated: 2021/10/19 21:13:40 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_chunklist(t_stacks *data)
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

void	ft_chunks(t_stacks *data)
{
	ft_chunklist(data);
	// if (data->a_heigth > CHUNKSIZE)
	// {
	// 	data->ch = 2;
	// 	data->total_ch = (data->a_heigth / CHUNKSIZE) + 1;
	// }
	// else
	// 	data->ch = 1;
}

void	ft_listupdate(t_stacks *data)
{
	int		pos;

	pos = 0;
	while (data->list[pos] != SB[0])
		pos++;
	while (pos <= data->a_heigth - 1)
	{
		data->list[pos] = data->list[pos + 1];
		pos++;
	}
}