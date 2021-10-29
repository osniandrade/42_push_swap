/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   side1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 20:04:52 by ocarlos-          #+#    #+#             */
/*   Updated: 2021/10/29 18:26:59 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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
}

// prints data->la, data->lb, stack names and separation lines on terminal
void	ft_printoprt(char *msg)
{
	ft_putstr_fd(msg, 1);
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
