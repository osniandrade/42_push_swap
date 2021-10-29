/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 20:13:02 by ocarlos-          #+#    #+#             */
/*   Updated: 2021/10/29 18:09:04 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// exits the code and frees memory allocations
void	ft_exit(t_stks *data)
{
	free (data->la);
	free (data->lb);
	exit(0);
}

// checks the stack size and which algorithm will be used to sort it
void	ft_stacksize(t_stks *data)
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

int	main(int argc, char **argv)
{
	t_stks	data;
	t_list	*a;
	t_list	*b;

	data = (t_stks){0};
	ft_checkargs(argc, argv);
	a = malloc(sizeof(t_list) * argc);
	b = malloc(sizeof(t_list) * argc);
	data.la = (t_list *)a;
	data.lb = (t_list *)b;
	ft_initstacks(&data, argc);
	ft_loadstack(&data, argv);
	ft_stacksize(&data);
	ft_exit(&data);
	return (0);
}
