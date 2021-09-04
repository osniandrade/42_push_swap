/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flow1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 09:13:38 by ocarlos-          #+#    #+#             */
/*   Updated: 2021/09/04 16:15:31 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// stack size = 2
void	ft_stack_small(t_stacks *data)
{
	if (SA[0] > SA[1])
		ft_sa(data, TRUE);
}

// stack size = 3
void	ft_stack_mid(t_stacks *data)
{
	if (SA[1] < SA[0] && SA[0] < SA[2])
		ft_sa(data, TRUE);
	else if (SA[2] < SA[1] && SA[1] < SA[0])
	{
		ft_sa(data, TRUE);
		ft_rra(data, TRUE);
	}
	else if (SA[1] < SA[2] && SA[2] < SA[0])
		ft_ra(data, TRUE);
	else if (SA[0] < SA[2] && SA[2] < SA[1])
	{
		ft_sa(data, TRUE);
		ft_ra(data, TRUE);
	}
	else if (SA[2] < SA[1] && SA[0] < SA[1])
		ft_rra(data, TRUE);
}

// stack size = 4 or 5
void	ft_stack_big(t_stacks *data)
{
	int	r;

	r = 0;
	if(ft_flowcase1(data))
		return ;
	if(data->a_heigth == 3)
		ft_pa(data, TRUE);
	ft_pa(data, TRUE);
}

// stack size > 5
void	ft_stack_huge(t_stacks *data)
{
	if (ft_singlemove1(data))
		return ;
	if (ft_singlemove2(data))
		return ;
	while (data->a_heigth > 0)
	{
		ft_pushlowest1(data);
		if (SB[0] < SA[0] && ft_sa_in_order(data))
			break;
	}
	while (data->b_heigth != 0)
		ft_pa(data, TRUE);
}
