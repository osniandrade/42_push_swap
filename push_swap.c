/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 20:13:02 by ocarlos-          #+#    #+#             */
/*   Updated: 2021/05/23 11:33:49 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

//TEMPORARY
static void	ft_printargs(int argc)
{
	ft_putstr_fd("argc = ", 1);
	ft_putnbr_fd(argc, 1);
	ft_putchar_fd('\n', 1);
}

int		main(int argc, char **argv)
{
	t_stacks data;
	int	a[argc];
	int	b[argc];

	data = (t_stacks) {0};
	ft_initstacks(&data, argc, (int *)&a, (int *)&b);
	//TEMPORARY
	ft_printargs(argc);
	ft_loadstack(&data, argv);
	ft_printstack(&data);
	ft_testfunc(&data);
	return (0);
}