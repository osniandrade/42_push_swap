/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 11:20:50 by ocarlos-          #+#    #+#             */
/*   Updated: 2021/09/14 00:17:06 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

/*
void	teste()
{
	int size = a.size();
	int max_num = size - 1; // the biggest number in a is stack_size - 1
	int max_bits = 0; // how many bits for max_num 
	while ((max_num >> max_bits) != 0) ++max_bits;
	for (int i = 0 ; i < max_bits ; ++i) // repeat for max_bits times
	{
		for(int j = 0 ; j < size ; ++j)
		{
			int num = a.top(); // top number of A
			if ((num >> i)&1 == 1) ra(); 
			// if the (i + 1)-th bit is 1, leave in stack a
			else pb();
			// otherwise push to stack b
		}
		// put into boxes done
		while (!b.empty()) pa(); // while stack b is not empty, do pa
		
		// connect numbers done
	}
}
*/