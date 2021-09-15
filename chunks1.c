/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 13:35:34 by ocarlos-          #+#    #+#             */
/*   Updated: 2021/09/15 21:47:38 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_chunklist(t_stacks *data)
{
	int		swaps;
	int		smallest;
	int		temp;
	
	swaps = 0;
	data->c = 0;
	smallest = 0;
	while (data->c < data->a_heigth)
	{
		data->list[data->c] = SA[data->c];
		data->c++;
	}
	while (swaps < data->a_heigth)
	{
		data->c = 0;
		smallest = 0;
		// lembrar de renomear e picar as funções
		// armazenar o menor e o segundo menor a cada loop e trocar na SA pelo valor do SWAPS
		while (data->c < data->a_heigth)
		{
			if (data->list[data->c] < data->list[smallest] && data->control[data->c] == 0)
				smallest = data->c;
			data->c++;
		}
		SA[smallest] = swaps;
		data->control[smallest] = 1;
		swaps++;
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