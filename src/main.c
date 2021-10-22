/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 22:30:47 by ocarlos-          #+#    #+#             */
/*   Updated: 2021/10/21 23:40:30 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

t_node	*ft_newlist(int argc, char ** argv)
{
	t_node	*list;

	list = malloc(sizeof(t_node) * (argc - 1));
	list->value = ft_atoi(argv[0]);
	list->next->value = ft_atoi(argv[1]);
	list->next->next = list;
	return (list);
}

int	main(int argc, char **argv)
{
	t_node *list;
	
	argv++;
	printf("%d\n", argc);
	list = ft_newlist(argc, argv);
	printf("%d\n", list->value);
	free (list);
	//ft_lstclear(&list, free);
	return (0);
}