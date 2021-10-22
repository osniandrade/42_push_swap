/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   side2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 11:20:50 by ocarlos-          #+#    #+#             */
/*   Updated: 2021/10/22 19:22:21 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// moves every element of a stack down 1 space
void	ft_movealldown(t_stacks *data, int *heigth, int *stack)
{
	int c;

	if (*heigth <= data->max_heigth)
	{
		c = *heigth;
		while (c > 0)
		{
			stack[c] = stack[c - 1];
			c--;
		}
		stack[0] = 0;
	}
}

// moves every element of a stack up 1 space
void	ft_moveallup(t_stacks *data, int *heigth, int *stack)
{
	int	i;

	if (*heigth > 0)
	{
		i = 0;
		while (i < *heigth)
		{
			stack[i] = stack[i + 1];
			i++;
		}
		stack[*heigth] = 0;
	}
}

// swaps the first 2 elements of stack a
void	ft_sa(t_stacks *data, int print)
{
	int	i;

	if (data->a_heigth > 0)
	{
		i = SA[0];
		SA[0] = SA[1];
		SA[1] = i;
		data->moves++;
		if (print)
			ft_printstack(data, "Exec sa:");
	}
}

// swaps the first 2 elements of stack b
void	ft_sb(t_stacks *data, int print)
{
	int	i;

	if (data->b_heigth > 0)
	{
		i = SB[0];
		SB[0] = SB[1];
		SB[1] = i;
		data->moves++;
		if (print)
			ft_printstack(data, "Exec sb:");
	}
}

