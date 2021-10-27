/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 20:13:37 by ocarlos-          #+#    #+#             */
/*   Updated: 2021/10/27 20:23:03 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <stdlib.h>
# include <unistd.h>
//TEMPORARY
# include <stdio.h>

# define SEPARATOR "-------------\n"
# define BOTTOM "_\t_\n"
# define STACKNAME "a\tb\n"
# define TRUE 1
# define FALSE 0
# define SA data->a
# define SB data->b
# define LIST data->list
# define CHUNKSIZE 20

typedef struct	s_stacks
{
	int			*a;
	int			*b;
	int			*list;
	int			a_heigth;
	int			b_heigth;
	int			max_heigth;
	int			moves;
}				t_stacks;

typedef	struct	s_lowest
{
	int			lowest;
	int			last;
	int			i;
	int			p;
	int			c;
}				t_lowest;

//main.c
void		ft_stacksize(t_stacks *data);

//helper.c
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
int			ft_isdigit(int c);
int			ft_atoi(const char *str);

//side1.c
void		ft_deflines(int k);
void		ft_loadstack(t_stacks *data, char **argv);
void		ft_printfullsack(t_stacks *data, char *msg);
void		ft_printstack(t_stacks *data, char *msg);
void		ft_initstacks(t_stacks *data, int argc, int *a, int *b);

//side2.c
void		ft_movealldown(t_stacks *data, int *heigth, int *stack);
void		ft_moveallup(t_stacks *data, int *heigth, int *stack);
void		ft_sa(t_stacks *data, int print);
void		ft_sb(t_stacks *data, int print);

//side3.c
void		ft_ss(t_stacks *data, int print);
void		ft_pa(t_stacks *data, int print);
void		ft_pb(t_stacks *data, int print);
void		ft_ra(t_stacks *data, int print);
void		ft_rb(t_stacks *data, int print);

//side4.c
void		ft_rr(t_stacks *data, int print);
void		ft_rra(t_stacks *data, int print);
void		ft_rrb(t_stacks *data, int print);
void		ft_rrr(t_stacks *data, int print);

//flow1.c
void		ft_stack_small(t_stacks *data);
void		ft_stack_mid(t_stacks *data);
void		ft_stack_big(t_stacks *data);
void		ft_stack_huge(t_stacks *data);

//cases1.c
int			ft_flowcase1(t_stacks *data);
t_lowest	ft_findlowest(t_stacks *data);
void		ft_pushlowest(t_stacks *data);

//validate1.c
void		ft_error();
void		ft_checkargs(int argc, char **argv);
void		ft_checknumbers(t_stacks *data);
int			ft_ready(t_stacks *data);

//move1.c
int			ft_singlemove1(t_stacks *data);
int			ft_singlemove2(t_stacks *data);

//helperlist.c
void		ft_normalize(t_stacks *data);
void		ft_movelist(t_stacks *data);
void		ft_sortlist(t_stacks *data);
void		ft_helperlist(t_stacks *data);

//exit.c
void		ft_exit(t_stacks *data);

#endif