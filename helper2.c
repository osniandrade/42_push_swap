/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 20:18:45 by ocarlos-          #+#    #+#             */
/*   Updated: 2021/10/29 18:10:12 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// tests if character is a blank space
int	ft_tstspc(const char ch)
{
	if ((ch == ' ') || (ch == '\f') || (ch == '\n')
		|| (ch == '\r') || (ch == '\t') || (ch == '\v'))
		return (1);
	return (0);
}

// checks if character is a digit
int	ft_isdigit(int c)
{
	if ((c >= 48) && (c <= 57))
		return (1);
	else
		return (0);
}

// converts a string to integer
int	ft_atoi(const char *str, t_stks *data)
{
	int			signal;
	long int	num;
	int			number;

	signal = 1;
	num = 0;
	while (ft_tstspc(*str))
		str++;
	if ((*str == '+') || (*str == '-'))
		if (*str++ == '-')
			signal *= -1;
	if (!(ft_isdigit(*str)))
		return (0);
	while (ft_isdigit(*str))
		num = num * 10 + (*str++ - 48);
	if ((num > __INT_MAX__ && signal == 1)
		|| (num - 1 > __INT_MAX__ && signal == -1))
		ft_error(data, 1);
	number = num;
	return (number * signal);
}
