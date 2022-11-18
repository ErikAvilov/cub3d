/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavilov <eavilov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:19:42 by eavilov           #+#    #+#             */
/*   Updated: 2022/11/17 13:54:54 by eavilov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddback(t_list **lst, t_list *new)
{
	t_list	*begin;

	begin = *lst;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	while ((*lst)->next)
		(*lst) = (*lst)->next;
	(*lst)->next = new;
	*lst = begin;
	return ;
}

t_list	*ft_lstaddnew(void *content)
{
	t_list	*ptr;

	ptr = malloc(sizeof(t_list));
	if (!ptr)
		return (NULL);
	ptr->content = content;
	ptr->next = NULL;
	return (ptr);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*newlst;
	void	*content;

	newlst = NULL;
	while (lst)
	{
		content = (*f)(lst->content);
		tmp = ft_lstaddnew(content);
		if (!tmp)
		{
			del(content);
			while (newlst)
			{
				tmp = newlst->next;
				del(newlst->content);
				free(newlst);
				newlst = tmp;
			}
			return (NULL);
		}
		ft_lstaddback(&newlst, tmp);
		lst = lst -> next;
	}
	return (newlst);
}
