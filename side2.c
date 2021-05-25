/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   side2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 11:20:50 by ocarlos-          #+#    #+#             */
/*   Updated: 2021/05/25 11:19:03 by ocarlos-         ###   ########.fr       */
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
	}
}

// swaps the first 2 elements of stack a
void	ft_sa(t_stacks *data, int print)
{
	if (data->a_heigth > 0)
	{
		data->c = data->a[0];
		data->a[0] = data->a[1];
		data->a[1] = data->c;
		if (print)
			ft_printstack(data, "Exec sa:");
	}
}

// swaps the first 2 elements of stack b
void	ft_sb(t_stacks *data, int print)
{
	if (data->b_heigth > 0)
	{
		data->c = data->b[0];
		data->b[0] = data->b[1];
		data->b[1] = data->c;
		if (print)
			ft_printstack(data, "Exec sb:");
	}
}

// swaps the first 2 elements of both stacks
void	ft_ss(t_stacks *data, int print)
{
	if (data->a_heigth > 0 && data->b_heigth > 0)
	{
		ft_sa(data, FALSE);
		ft_sb(data, FALSE);
		if (print)
			ft_printstack(data, "Exec ss:");
	}
}

// pushes the first elements of stack b to stack a
void	ft_pa(t_stacks *data, int print)
{
	if (data->b_heigth > 0)
	{
		ft_movealldown(data, &data->a_heigth, data->a);
		data->a_heigth += 1;
		data->a[0] = data->b[0];
		ft_moveallup(data, &data->b_heigth, data->b);
		data->b_heigth -= 1;
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
		data->b[0] = data->a[0];
		ft_moveallup(data, &data->a_heigth, data->a);
		data->a_heigth -= 1;
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
		temp = data->a[0];
		ft_moveallup(data, &data->a_heigth, data->a);
		data->a[data->a_heigth - 1] = temp;
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
		temp = data->b[0];
		ft_moveallup(data, &data->b_heigth, data->b);
		data->b[data->b_heigth - 1] = temp;
		if (print)
			ft_printstack(data, "Exec rb:");
	}
}

// ra and rb at the same time
void	ft_rr(t_stacks *data, int print)
{
	if (data->b_heigth > 1 && data->a_heigth > 1)
	{
		ft_ra(data, FALSE);
		ft_rb(data, FALSE);
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
		temp = data->a[data->a_heigth - 1];
		ft_movealldown(data, &data->a_heigth, data->a);
		data->a[0] = temp;
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
		temp = data->b[data->b_heigth - 1];
		ft_movealldown(data, &data->b_heigth, data->b);
		data->b[0] = temp;
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
		if (print)
			ft_printstack(data, "Exec rrr:");
	}
}
