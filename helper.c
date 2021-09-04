/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 20:18:45 by ocarlos-          #+#    #+#             */
/*   Updated: 2021/09/02 20:16:47 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int		ft_tstspc(const char ch)
{
	if ((ch == ' ') || (ch == '\f') || (ch == '\n') ||
		(ch == '\r') || (ch == '\t') || (ch == '\v'))
		return (1);
	return (0);
}

void	ft_putchar_fd(char c, int fd)
{
	unsigned char	ch;

	ch = (unsigned char)c;
	write(fd, &ch, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
		while (*s != '\0')
			ft_putchar_fd(*s++, fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int num;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		num = n * -1;
	}
	else
		num = n;
	if (num < 10)
		ft_putchar_fd(num + '0', fd);
	if ((num / 10) > 0)
	{
		ft_putnbr_fd(num / 10, fd);
		ft_putchar_fd(num % 10 + '0', fd);
	}
}

int		ft_isdigit(int c)
{
	if ((c >= 48) && (c <= 57))
		return (1);
	else
		return (0);
}

int		ft_atoi(const char *str)
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
	if ((num > __INT_MAX__ && signal == 1) ||
		(num - 1 > __INT_MAX__ && signal == -1))
			ft_error();
	number = num;
	return (number * signal);
}