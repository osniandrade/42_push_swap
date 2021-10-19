/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 20:13:02 by ocarlos-          #+#    #+#             */
/*   Updated: 2021/10/19 21:07:51 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

//TEMPORARY
static void	ft_printargs(int moves)
{
	ft_putstr_fd("moves = ", 1);
	ft_putnbr_fd(moves, 1);
	ft_putchar_fd('\n', 1);
}

void	ft_stacksize(t_stacks *data)
{
	if (data->max_heigth == 0)
		return ;
	else if (data->max_heigth == 1)
		return ;
	else if (data->max_heigth == 2)
		ft_stack_small(data);
	else if (data->max_heigth == 3)
		ft_stack_mid(data);
	else if (data->max_heigth <= 5)
		ft_stack_big(data);
	else
		ft_stack_huge(data);
}

int		main(int argc, char **argv)
{
	t_stacks data;
	int	a[argc];
	int	b[argc];

	data = (t_stacks) {0};
	ft_checkargs(argc, argv);
	ft_initstacks(&data, argc, (int *)&a, (int *)&b);
	ft_loadstack(&data, argv);
	ft_chunks(&data);
	//ft_testfunc(&data);
	ft_stacksize(&data);
	ft_printargs(data.moves);
	ft_exit(&data);
	return (0);
}
