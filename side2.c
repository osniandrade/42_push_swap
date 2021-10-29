/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   side2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 11:20:50 by ocarlos-          #+#    #+#             */
/*   Updated: 2021/10/29 12:52:09 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// moves every element of a stack down 1 space
void	ft_movealldown(t_stacks *data, int *heigth, t_list *stack)
{
	int	c;

	if (*heigth <= data->max_heigth)
	{
		c = *heigth;
		while (c > 0)
		{
			stack[c] = stack[c - 1];
			c--;
		}
		stack[0] = (t_list){0};
	}
}

// moves every element of a stack up 1 space
void	ft_moveallup(t_stacks *data, int *heigth, t_list *stack)
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
		stack[*heigth] = (t_list){0};
	}
}

// swaps the first 2 elements of stack a
void	ft_sa(t_stacks *data, int print)
{
	t_list	i;

	if (data->a_heigth > 0)
	{
		i = data->la[0];
		data->la[0] = data->la[1];
		data->la[1] = i;
		data->moves++;
		if (print)
			ft_printstack(data, "Exec data->la:");
	}
}

// swaps the first 2 elements of stack b
void	ft_sb(t_stacks *data, int print)
{
	t_list	i;

	if (data->b_heigth > 0)
	{
		i = data->lb[0];
		data->lb[0] = data->lb[1];
		data->lb[1] = i;
		data->moves++;
		if (print)
			ft_printstack(data, "Exec data->lb:");
	}
}
