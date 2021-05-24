/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 20:13:37 by ocarlos-          #+#    #+#             */
/*   Updated: 2021/05/24 14:23:36 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
//TEMPORARY
#include <stdio.h>

#define SEPARATOR "-------------\n"
#define BOTTOM "_\t_\n"
#define STACKNAME "a\tb\n"

typedef struct  s_stacks
{
    int         *a;
    int         *b;
    int         c;
    int         a_heigth;
    int         b_heigth;
    int         max_heigth;
}               t_stacks;

//helper.c
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);

//side1.c
void	ft_deflines(int k);
void    ft_loadstack(t_stacks *data, char **argv);
void    ft_printstack(t_stacks *data, char *msg);
void	ft_initstacks(t_stacks *data, int argc, int *a, int *b);

//side2.c
void	ft_movealldown(t_stacks *data, int *heigth, int *stack);
void	ft_moveallup(t_stacks *data, int *heigth, int *stack);
void    ft_sa(t_stacks *data);
void	ft_sb(t_stacks *data);
void	ft_ss(t_stacks *data);
void	ft_push_a(t_stacks *data);
void	ft_push_b(t_stacks *data);

//test.c
void	ft_testfunc(t_stacks *data);