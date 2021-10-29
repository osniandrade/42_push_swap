/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   side3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 11:20:50 by ocarlos-          #+#    #+#             */
/*   Updated: 2021/10/29 18:26:59 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// swaps the first 2 elements of both stacks
void	ft_ss(t_stks *data, int print)
{
	if (data->a_heigth > 0 && data->b_heigth > 0)
	{
		ft_sa(data, FALSE);
		ft_sb(data, FALSE);
		data->moves--;
		if (print)
			ft_printoprt("ss");
	}
}

// pushes the first elements of stack b to stack a
void	ft_pa(t_stks *data, int print)
{
	if (data->b_heigth > 0)
	{
		ft_movealldown(data, &data->a_heigth, data->la);
		data->a_heigth += 1;
		data->la[0] = data->lb[0];
		ft_moveallup(&data->b_heigth, data->lb);
		data->b_heigth -= 1;
		data->moves++;
		if (print)
			ft_printoprt("pa");
	}
}

// pushes the first elements of stack a to stack b
void	ft_pb(t_stks *data, int print)
{
	if (data->a_heigth > 0)
	{
		ft_movealldown(data, &data->b_heigth, data->lb);
		data->b_heigth += 1;
		data->lb[0] = data->la[0];
		ft_moveallup(&data->a_heigth, data->la);
		data->a_heigth -= 1;
		data->moves++;
		if (print)
			ft_printoprt("pb");
	}
}

// shifts up all elements of A by 1. the first element becomes the last one
void	ft_ra(t_stks *data, int print)
{
	t_list	temp;

	if (data->a_heigth > 1)
	{
		temp = data->la[0];
		ft_moveallup(&data->a_heigth, data->la);
		data->la[data->a_heigth - 1] = temp;
		data->moves++;
		if (print)
			ft_printoprt("ra");
	}
}

// shifts up all elements of B by 1. the first element becomes the last one
void	ft_rb(t_stks *data, int print)
{
	t_list	temp;

	if (data->b_heigth > 1)
	{
		temp = data->lb[0];
		ft_moveallup(&data->b_heigth, data->lb);
		data->lb[data->b_heigth - 1] = temp;
		data->moves++;
		if (print)
			ft_printoprt("rb");
	}
}
