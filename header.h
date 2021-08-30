/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 20:13:37 by ocarlos-          #+#    #+#             */
/*   Updated: 2021/05/26 14:03:54 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
//TEMPORARY
#include <stdio.h>

#define SEPARATOR "-------------\n"
#define BOTTOM "_\t_\n"
#define STACKNAME "a\tb\n"
#define TRUE 1
#define FALSE 0
#define SA data->a
#define SB data->b

typedef	struct	s_list
{
	void			*content;
	struct 	s_list	*next;
}				t_list;
typedef struct	s_stacks
{
	t_list		*a_list;
	t_list		*b_list;
	int			*a;
	int			*b;
	int			c;
	int			a_heigth;
	int			b_heigth;
	int			max_heigth;
	int			moves;
}				t_stacks;

//main.c
void	ft_stacksize(t_stacks *data);

//helper.c
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);

//side1.c
void	ft_deflines(int k);
void	ft_loadstack(t_stacks *data, char **argv);
void	ft_printstack(t_stacks *data, char *msg);
void	ft_initstacks(t_stacks *data, int argc, int *a, int *b);
int		ft_ready(t_stacks *data);
int		ft_singlemove(t_stacks *data);

//side2.c
void	ft_movealldown(t_stacks *data, int *heigth, int *stack);
void	ft_moveallup(t_stacks *data, int *heigth, int *stack);
void	ft_sa(t_stacks *data, int print);
void	ft_sb(t_stacks *data, int print);
void	ft_ss(t_stacks *data, int print);
void	ft_pa(t_stacks *data, int print);
void	ft_pb(t_stacks *data, int print);
void	ft_ra(t_stacks *data, int print);
void	ft_rb(t_stacks *data, int print);
void	ft_rr(t_stacks *data, int print);
void	ft_rra(t_stacks *data, int print);
void	ft_rrb(t_stacks *data, int print);
void	ft_rrr(t_stacks *data, int print);

//test.c
void	ft_testfunc(t_stacks *data);

//flow1.c
void	ft_stack_small(t_stacks *data);
void	ft_stack_mid(t_stacks *data);
void	ft_stack_big(t_stacks *data);
void	ft_stack_huge(t_stacks *data);
