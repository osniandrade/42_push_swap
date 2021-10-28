/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   side4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 11:20:50 by ocarlos-          #+#    #+#             */
/*   Updated: 2021/09/07 13:33:48 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// ra and rb at the same time
void	ft_rr(t_stacks *data, int print)
{
	if (data->b_heigth > 1 && data->a_heigth > 1)
	{
		ft_ra(data, FALSE);
		ft_rb(data, FALSE);
		data->moves--;
		if (print)
			ft_printstack(data, "Exec rr:");
	}
}

// shifts down all elements of A by 1. the last element becomes the first one
void	ft_rra(t_stacks *data, int print)
{
	int		temp;

	if (data->a_heigth > 1)
	{
		temp = SA[data->a_heigth - 1];
		ft_movealldown(data, &data->a_heigth, SA);
		SA[0] = temp;
		data->moves++;
		if (print)
			ft_printstack(data, "Exec rra:");
	}
}

// shifts down all elements of B by 1. the last element becomes the first one
void	ft_rrb(t_stacks *data, int print)
{
	int		temp;

	if (data->b_heigth > 1)
	{
		temp = SB[data->b_heigth - 1];
		ft_movealldown(data, &data->b_heigth, SB);
		SB[0] = temp;
		data->moves++;
		if (print)
			ft_printstack(data, "Exec rrb:");
	}
}

// rra and rrb at the same time
void	ft_rrr(t_stacks *data, int print)
{
	if (data->a_heigth > 1 && data->b_heigth > 1)
	{
		ft_rra(data, FALSE);
		ft_rrb(data, FALSE);
		data->moves--;
		if (print)
			ft_printstack(data, "Exec rrr:");
	}
}
