/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 20:13:37 by ocarlos-          #+#    #+#             */
/*   Updated: 2021/10/29 17:22:41 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <stdlib.h>
# include <unistd.h>
# define SEPARATOR "-------------\n"
# define BOTTOM "_\t_\n"
# define STACKNAME "a\tb\n"
# define TRUE 1
# define FALSE 0
# define CHUNKSIZE 20

typedef struct s_list
{
	int			o;
	int			n;
}				t_list;

typedef struct s_stks
{
	t_list		*la;
	t_list		*lb;
	int			*list;
	int			a_heigth;
	int			b_heigth;
	int			max_heigth;
	int			moves;
}				t_stks;

typedef struct s_var
{
	int			max;
	int			last;
	int			i;
	int			p;
	int			c;
}				t_var;

//main.c
static void	ft_printargs(int moves);
void		ft_exit(t_stks *data);
void		ft_stacksize(t_stks *data);
void		ft_stacksize(t_stks *data);

//helper1.c
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);

//helper2.c
static int	ft_tstspc(const char ch);
int			ft_isdigit(int c);
int			ft_atoi(const char *str, t_stks *data);

//side1.c
void		ft_deflines(int k);
void		ft_loadstack(t_stks *data, char **argv);
void		ft_printfullsack(t_stks *data, char *msg);
void		ft_printstack(t_stks *data, char *msg);
void		ft_initstacks(t_stks *data, int argc);

//side2.c
void		ft_movealldown(t_stks *data, int *heigth, t_list *stack);
void		ft_moveallup(t_stks *data, int *heigth, t_list *stack);
void		ft_sa(t_stks *data, int print);
void		ft_sb(t_stks *data, int print);

//side3.c
void		ft_ss(t_stks *data, int print);
void		ft_pa(t_stks *data, int print);
void		ft_pb(t_stks *data, int print);
void		ft_ra(t_stks *data, int print);
void		ft_rb(t_stks *data, int print);

//side4.c
void		ft_rr(t_stks *data, int print);
void		ft_rra(t_stks *data, int print);
void		ft_rrb(t_stks *data, int print);
void		ft_rrr(t_stks *data, int print);

//flow.c
void		ft_stack_small(t_stks *data);
void		ft_stack_mid(t_stks *data);
void		ft_stack_big(t_stks *data);
void		ft_stack_huge(t_stks *data);

//cases.c
int			ft_flowcase1(t_stks *data);
t_var		ft_findlowest(t_stks *data);
void		ft_pushlowest(t_stks *data);
void		ft_sorthuge(t_stks *data);

//validate.c
void		ft_error(t_stks *data, int clean);
void		ft_checkargs(int argc, char **argv);
void		ft_checknumbers(t_stks *data);
int			ft_ready(t_stks *data);

//move.c
int			ft_singlemove1(t_stks *data);
int			ft_singlemove2(t_stks *data);

//helperlist.c
void		ft_normalize(t_stks *data);

#endif