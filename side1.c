/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   side1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 20:04:52 by ocarlos-          #+#    #+#             */
/*   Updated: 2021/05/23 11:43:42 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_deflines(int k)
{
	if (k == 0)
		ft_putstr_fd(SEPARATOR, 1);
	if (k == 1)
	{
		ft_putstr_fd(BOTTOM, 1);
		ft_putstr_fd(STACKNAME, 1);
	}
}

void	ft_loadstack(t_stacks *data, char **argv)
{
	data->c = 0;
	while (data->c < data->a_heigth)
	{
		data->a[data->c] = ft_atoi(argv[data->c + 1]);
		data->c++;
	}
}

void	ft_printstack(t_stacks *data)
{
	data->c = 0;
	ft_deflines(0);
	ft_putstr_fd("Init a and b:\n", 1);
	while (data->c < data->a_heigth)
	{
		if (data->c < data->a_heigth)
			ft_putnbr_fd(data->a[data->c], 1);
		else
			ft_putchar_fd(' ', 1);
		ft_putchar_fd('\t', 1);
		if (data->c < data->b_heigth)
			ft_putnbr_fd(data->b[data->c], 1);
		else
			ft_putchar_fd(' ', 1);
		ft_putchar_fd('\n', 1);
		data->c++;
	}
	ft_deflines(1);
	ft_putchar_fd('\n', 1);
}

void	ft_initstacks(t_stacks *data, int argc, int *a, int *b)
{
	data->a = (int *)a;
	data->b = (int *)b;
	data->a_heigth = argc - 1;
	data->max_heigth = argc - 1;
	while (data->c < data->a_heigth)
	{
		data->a[data->c] = 0;
		data->b[data->c] = 0;
		data->c++;
	}
}
