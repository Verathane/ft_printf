/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbond <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 19:03:32 by nbond             #+#    #+#             */
/*   Updated: 2016/12/01 22:48:13 by nbond            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *newlist;
	t_list *head;

	if (lst)
	{
		newlist = ft_lstnew((f(lst))->content, (f(lst))->content_size);
		head = newlist;
	}
	else
		return (NULL);
	while (lst->next)
	{
		newlist->next = ft_lstnew((f(lst->next))->content, \
				(f(lst->next))->content_size);
		if (!(newlist->next))
			return (NULL);
		newlist = newlist->next;
		lst = lst->next;
	}
	return (head);
}
