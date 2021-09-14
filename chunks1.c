/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 13:35:34 by ocarlos-          #+#    #+#             */
/*   Updated: 2021/09/14 00:16:56 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_chunklist(t_stacks *data)
{
	int		temp;
	int		pos;
	int		swaps;
	int		smallest;
	
	data->c = data->a_heigth - 1;
	swaps = 0;
	pos = 0;
	smallest = SA[0];
	while (swaps < data->a_heigth)
	{
		while (pos < data->a_heigth)
		{
			if (data->list[pos] < smallest)
			{
				// ENCONTRAR O MENOR DA SA
				// E TROCAR PELO EQUIVALENTE
				// NO LIST
			}
			data->c--;
		}
	}
}

void	ft_chunks(t_stacks *data)
{
	ft_chunklist(data);
	if (data->a_heigth > CHUNKSIZE)
	{
		data->ch = 2;
		data->total_ch = (data->a_heigth / CHUNKSIZE) + 1;
	}
	else
		data->ch = 1;
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