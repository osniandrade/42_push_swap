/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   side1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 20:04:52 by ocarlos-          #+#    #+#             */
/*   Updated: 2021/09/09 23:39:49 by ocarlos-         ###   ########.fr       */
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
	long int	number;
	int			list[data->a_heigth];
	
	data->c = 1;
	data->list = (int *)list;
	while (data->c <= data->a_heigth)
	{
		number = ft_atoi(argv[data->c]);
		SA[data->c - 1] = number;
		data->list[data->c - 1] = number;
		data->c++;
	}
	ft_checknumbers(data);
	if (ft_ready(data))
		exit(0);
	ft_printstack(data, "Init a and b:");
}

void	ft_printfullsack(t_stacks *data, char *msg)
{
	int		highest;
	
	ft_putchar_fd('\n', 1);
	if (data->a_heigth >= data->b_heigth)
		highest = data->a_heigth;
	else
		highest = data->b_heigth;
	while (data->c < highest)
	{
		if (data->c < data->a_heigth)
			ft_putnbr_fd(SA[data->c], 1);
		else
			ft_putchar_fd(' ', 1);
		ft_putchar_fd('\t', 1);
		if (data->c < data->b_heigth)
			ft_putnbr_fd(SB[data->c], 1);
		else
			ft_putchar_fd(' ', 1);
		ft_putchar_fd('\n', 1);
		data->c++;
	}
	ft_deflines(1);
}

void	ft_printstack(t_stacks *data, char *msg)
{
	data->c = 0;
	// START OF DEBUG ONLY
	usleep(50000);
	//system("@cls||clear");
	// END OF DEBUG ONLY
	ft_deflines(0);
	ft_putstr_fd(msg, 1);
	ft_printfullsack(data, msg);
	ft_putchar_fd('\n', 1);
}

void	ft_initstacks(t_stacks *data, int argc, int *a, int *b)
{
	SA = (int *)a;
	SB = (int *)b;
	data->a_heigth = argc - 1;
	data->max_heigth = argc - 1;
	while (data->c <= data->a_heigth)
	{
		SA[data->c] = 0;
		SB[data->c] = 0;
		data->c++;
	}
}
