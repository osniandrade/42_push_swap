/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   side3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 11:20:50 by ocarlos-          #+#    #+#             */
/*   Updated: 2021/09/07 13:33:33 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// swaps the first 2 elements of both stacks
void	ft_ss(t_stacks *data, int print)
{
	if (data->a_heigth > 0 && data->b_heigth > 0)
	{
		ft_sa(data, FALSE);
		ft_sb(data, FALSE);
		data->moves--;
		if (print)
			ft_printstack(data, "Exec ss:");
	}
}

// pushes the first elements of stack b to stack a
void	ft_pa(t_stacks *data, int print)
{
	if (data->b_heigth > 0)
	{
		ft_movealldown(data, &data->a_heigth, SA);
		data->a_heigth += 1;
		SA[0] = SB[0];
		ft_moveallup(data, &data->b_heigth, data->b);
		data->b_heigth -= 1;
		data->moves++;
		if (print)
			ft_printstack(data, "Exec pa:");
	}
}

// pushes the first elements of stack a to stack b
void	ft_pb(t_stacks *data, int print)
{
	if (data->a_heigth > 0)
	{
		ft_movealldown(data, &data->b_heigth, data->b);
		data->b_heigth += 1;
		SB[0] = SA[0];
		ft_moveallup(data, &data->a_heigth, SA);
		data->a_heigth -= 1;
		data->moves++;
		if (print)
			ft_printstack(data, "Exec pb:");
	}
}

// shifts up all elements of A by 1. the first element becomes the last one
void	ft_ra(t_stacks *data, int print)
{
	int		temp;

	if (data->a_heigth > 1)
	{
		temp = SA[0];
		ft_moveallup(data, &data->a_heigth, SA);
		SA[data->a_heigth - 1] = temp;
		data->moves++;
		if (print)
			ft_printstack(data, "Exec ra:");
	}
}

// shifts up all elements of B by 1. the first element becomes the last one
void	ft_rb(t_stacks *data, int print)
{
	int		temp;

	if (data->b_heigth > 1)
	{
		temp = SB[0];
		ft_moveallup(data, &data->b_heigth, data->b);
		SB[data->b_heigth - 1] = temp;
		data->moves++;
		if (print)
			ft_printstack(data, "Exec rb:");
	}
}
