/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   side1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 20:04:52 by ocarlos-          #+#    #+#             */
/*   Updated: 2021/10/27 22:26:48 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// prints the separator line between moves OR
// prints the stack name with the separador line
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

// loads input args into SA and into the secondary list
void	ft_loadstack(t_stacks *data, char **argv)
{
	long int	number;
	int			i;
	
	i = 1;
	data->list = (int *) calloc (data->a_heigth, sizeof(int));
	while (i <= data->a_heigth)
	{
		number = ft_atoi(argv[i]);
		SA[i - 1] = number;
		data->list[i - 1] = number;
		i++;
	}
	ft_checknumbers(data);
	if (ft_ready(data))
		ft_exit(data);
	ft_printstack(data, "Init a and b:");
}

// prints SA and SB on terminal
void	ft_printfullsack(t_stacks *data, char *msg)
{
	int		highest;
	int		i;
	
	i = 0;
	ft_putchar_fd('\n', 1);
	if (data->a_heigth >= data->b_heigth)
		highest = data->a_heigth;
	else
		highest = data->b_heigth;
	while (i < highest)
	{
		if (i < data->a_heigth)
			ft_putnbr_fd(SA[i], 1);
		else
			ft_putchar_fd(' ', 1);
		ft_putchar_fd('\t', 1);
		if (i < data->b_heigth)
			ft_putnbr_fd(SB[i], 1);
		else
			ft_putchar_fd(' ', 1);
		ft_putchar_fd('\n', 1);
		i++;
	}
	ft_deflines(1);
}

// prints SA, SB, stack names and separation lines on terminal
void	ft_printstack(t_stacks *data, char *msg)
{
	int	i;

	i = 0;
	// START OF DEBUG ONLY
	usleep(20000);
	//system("@cls||clear");
	// END OF DEBUG ONLY
	ft_deflines(0);
	ft_putstr_fd(msg, 1);
	ft_printfullsack(data, msg);
	ft_putchar_fd('\n', 1);
}

// initializes the main struct
void	ft_initstacks(t_stacks *data, int argc, int *a, int *b)
{
	int	i;
	
	i = 0;
	SA = (int *)a;
	SB = (int *)b;
	data->a_heigth = argc - 1;
	data->max_heigth = argc - 1;
	while (i < data->a_heigth)
	{
		SA[i] = 0;
		SB[i] = 0;
		i++;
	}
}
