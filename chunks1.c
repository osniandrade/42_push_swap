/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 13:35:34 by ocarlos-          #+#    #+#             */
/*   Updated: 2021/09/07 14:18:47 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_chunklist(t_stacks *data)
{
	int		temp;
	
	data->c = data->a_heigth - 1;
	while (data->c > 0)
	{
		if (data->list[data->c] < data->list[data->c - 1])
		{
			temp = data->list[data->c];
			data->list[data->c] = data->list[data->c - 1];
			data->list[data->c - 1] = temp;
			data->c = data->a_heigth;
		}
		data->c--;
	}
}

void	ft_chunks(t_stacks *data)
{
	ft_chunklist(&data);
	if (data->a_heigth > CHUNKSIZE)
	{
		data->ch = 2;
		data->total_ch = (data->a_heigth / CHUNKSIZE) + 1;
	}
	else
		data->ch = 1;
}