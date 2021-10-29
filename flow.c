/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flow.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 09:13:38 by ocarlos-          #+#    #+#             */
/*   Updated: 2021/10/29 12:53:24 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// stack size = 2
void	ft_stack_small(t_stks *data)
{
	if (data->la[0].o > data->la[1].o)
		ft_sa(data, TRUE);
}

// stack size = 3
void	ft_stack_mid(t_stks *data)
{
	if (data->la[1].o < data->la[0].o && data->la[0].o < data->la[2].o)
		ft_sa(data, TRUE);
	else if (data->la[2].o < data->la[1].o && data->la[1].o < data->la[0].o)
	{
		ft_sa(data, TRUE);
		ft_rra(data, TRUE);
	}
	else if (data->la[1].o < data->la[2].o && data->la[2].o < data->la[0].o)
		ft_ra(data, TRUE);
	else if (data->la[0].o < data->la[2].o && data->la[2].o < data->la[1].o)
	{
		ft_sa(data, TRUE);
		ft_ra(data, TRUE);
	}
	else if (data->la[2].o < data->la[1].o && data->la[0].o < data->la[1].o)
		ft_rra(data, TRUE);
}

// stack size = 4 or 5
void	ft_stack_big(t_stks *data)
{
	int	r;

	r = 0;
	if (ft_flowcase1(data))
		return ;
	if (data->a_heigth == 3)
		ft_pa(data, TRUE);
	ft_pa(data, TRUE);
}

// stack size > 5
void	ft_stack_huge(t_stks *data)
{
	if (ft_ready(data))
		ft_exit(data);
	ft_helperlist(data);
	if (ft_singlemove1(data))
		return ;
	if (ft_singlemove2(data))
		return ;
	ft_sorthuge(data);
	ft_printstack(data, "finish");
}
