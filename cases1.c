/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 21:54:51 by ocarlos-          #+#    #+#             */
/*   Updated: 2021/08/31 22:03:20 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

//CASES USED IN FLOW1.C
void	ft_flowcase1(t_stacks *data)
{
    ft_pa(data, TRUE);
	if (ft_ready(data))
		return ;
}

void	ft_flowcase2(t_stacks *data)
{
	ft_pa(data, TRUE);
	ft_ra(data, TRUE);
	if (ft_ready(data))
		return ;
}