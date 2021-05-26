/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 11:27:22 by ocarlos-          #+#    #+#             */
/*   Updated: 2021/05/26 11:34:24 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// Allocates and returns a new element.  The variable ’content’ is
// initialized with the value of the parameter ’content’.
// The variable ’next’ is initialized to NULL.
t_list	*ft_lstnew(void *content)
{
	t_list	*head;

	if (!(head = malloc(sizeof(t_list))))
		return (NULL);
	head->content = content;
	head->next = NULL;
	return (head);
}

// Counts the number of elements in a list.
int		ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*node;

	i = 1;
	if (!(node = lst))
		return (0);
	while (node->next != NULL)
	{
		node = node->next;
		i++;
	}
	return (i);
}

// Iterates the list ’lst’ and applies the function ’f’ to the content of each
// element.  Creates a new list resulting of the successive applications of
// the function ’f’.  The ’del’ function is used to delete the content of an
// element if needed.
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*mov;

	if (!lst || !f)
		return (NULL);
	head = NULL;
	while (lst)
	{
		if (!(mov = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		ft_lstadd_back(&head, mov);
		lst = lst->next;
	}
	return (head);
}

// Returns the last element of the list.
t_list	*ft_lstlast(t_list *lst)
{
	t_list	*node;

	if (!(node = lst))
		return (0);
	while (node->next != NULL)
		node = node->next;
	return (node);
}

// Iterates the list ’lst’ and applies the function ’f’ to the content of
// each element.
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*node;

	node = lst;
	if (lst)
	{
		while (node)
		{
			f(node->content);
			node = node->next;
		}
	}
}

// Takes as a parameter an element and frees the memory of the element’s
// content using the function ’del’ given as a parameter and free the element.
// The memory of ’next’ must not be freed.
void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst)
	{
		del(lst->content);
		free(lst);
	}
}

// Deletes and frees the given element and every successor of that element,
// using the function ’del’ and 'free'. Finally, the pointer to the list
// must be set to NULL.
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*list;
	t_list	*nxtnode;

	if (!(list = *lst))
		return ;
	while (list)
	{
		nxtnode = list->next;
		del(list->content);
		free(list);
		list = nxtnode;
	}
	*lst = NULL;
}

// Adds the element ’new’ at the beginning of the list.
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

// Adds the element ’new’ at the end of the list.
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lastnode;

	if (!*lst)
		*lst = new;
	else
	{
		lastnode = ft_lstlast(*lst);
		lastnode->next = new;
		new->next = NULL;
	}
}
