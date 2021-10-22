/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 20:51:48 by ocarlos-          #+#    #+#             */
/*   Updated: 2021/10/22 19:34:49 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// exits the programs cleanly, freeing the list malloc
void    ft_exit(t_stacks *data)
{
    free(data->list);
    exit(0);
}