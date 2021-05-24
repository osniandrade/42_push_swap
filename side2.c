/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   side2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 11:20:50 by ocarlos-          #+#    #+#             */
/*   Updated: 2021/05/24 14:35:36 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// moves every element of a stack down 1 space
void	ft_movealldown(t_stacks *data, int *heigth, int *stack)
{
	int c;

	if (*heigth < data->max_heigth)
	{
		c = *heigth;
		while (c >= 0)
		{
			stack[c + 1] = stack[c];
			c--;
		}
		stack[0] = 0;
		*heigth += 1;
	}
}

// moves every element of a stack up 1 space
void	ft_moveallup(t_stacks *data, int *heigth, int *stack)
{
	int c;

	if (*heigth > 0)
	{
		c = 0;
		while (c < *heigth)
		{
			stack[c] = stack[c + 1];
			c++;
		}
		stack[*heigth] = 0;
		*heigth -= 1;
	}
}

// swaps the first 2 elements of stack a
void	ft_sa(t_stacks *data)
{
	if (data->a_heigth > 0)
	{
		data->c = data->a[0];
		data->a[0] = data->a[1];
		data->a[1] = data->c;
		ft_printstack(data, "sa:");
	}
}

// swaps the first 2 elements of stack b
void	ft_sb(t_stacks *data)
{
	if (data->b_heigth > 0)
	{
		data->c = data->b[0];
		data->b[0] = data->b[1];
		data->b[1] = data->c;
		ft_printstack(data, "sb:");
	}
}

// swaps the first 2 elements of both stacks
void	ft_ss(t_stacks *data)
{
	if (data->a_heigth > 0 && data->b_heigth > 0)
	{
		ft_sa(data);
		ft_sb(data);
		ft_printstack(data, "ss:");
	}
}

// pushes the first elements of stack b to stack a
void	ft_push_a(t_stacks *data)
{
	if (data->b_heigth > 0)
	{
		ft_movealldown(data, &data->a_heigth, data->a);
		data->a[0] = data->b[0];
		ft_moveallup(data, &data->b_heigth, data->b);
		ft_printstack(data, "push_a:");
	}
}

// pushes the first elements of stack a to stack b
void	ft_push_b(t_stacks *data)
{
	if (data->a_heigth > 0)
	{
		ft_movealldown(data, &data->b_heigth, data->b);
		data->b[0] = data->a[0];
		ft_moveallup(data, &data->a_heigth, data->a);
		ft_printstack(data, "push_b:");
	}
}