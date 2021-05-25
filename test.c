/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 11:20:50 by ocarlos-          #+#    #+#             */
/*   Updated: 2021/05/25 09:57:31 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//ENTIRELY TEMPORARY CODE

#include "header.h"

void	ft_testfunc(t_stacks *data)
{
	ft_sa(data, TRUE);	
	ft_pb(data, FALSE);
	ft_pb(data, FALSE);
	ft_pb(data, FALSE);
	ft_printstack(data, "Exec rb rb rb:");
	ft_rr(data, TRUE);
	ft_rrr(data, TRUE);
	ft_sa(data, TRUE);
	ft_pa(data, FALSE);
	ft_pa(data, FALSE);
	ft_pa(data, FALSE);
	ft_printstack(data, "Exec pa pa pa:");
}
