/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   side1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 20:04:52 by ocarlos-          #+#    #+#             */
/*   Updated: 2021/10/29 14:40:04 by ocarlos-         ###   ########.fr       */
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

// loads input args into data->la and into the secondary list
void	ft_loadstack(t_stks *data, char **argv)
{
	long int	number;
	int			i;

	i = 1;
	while (i <= data->a_heigth)
	{
		number = ft_atoi(argv[i], data);
		data->la[i - 1].o = number;
		i++;
	}
	ft_checknumbers(data);
	if (ft_ready(data))
		ft_exit(data);
	ft_printstack(data, "Init a and b:");
}

// prints data->la and data->lb on terminal
void	ft_printfullsack(t_stks *data, char *msg)
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
			ft_putnbr_fd(data->la[i].o, 1);
		else
			ft_putchar_fd(' ', 1);
		ft_putchar_fd('\t', 1);
		if (i < data->b_heigth)
			ft_putnbr_fd(data->lb[i].o, 1);
		else
			ft_putchar_fd(' ', 1);
		ft_putchar_fd('\n', 1);
		i++;
	}
	ft_deflines(1);
}

// prints data->la, data->lb, stack names and separation lines on terminal
void	ft_printstack(t_stks *data, char *msg)
{
	int	i;

	i = 0;
	ft_deflines(0);
	ft_putstr_fd(msg, 1);
	ft_printfullsack(data, msg);
	ft_putchar_fd('\n', 1);
}

// initializes the main struct
void	ft_initstacks(t_stks *data, int argc)
{
	int	i;

	i = 0;
	data->a_heigth = argc - 1;
	data->max_heigth = argc - 1;
	while (i < data->a_heigth)
	{
		data->la[i] = (t_list){0};
		data->lb[i] = (t_list){0};
		i++;
	}
}
