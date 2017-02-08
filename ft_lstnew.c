/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbond <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 15:17:23 by nbond             #+#    #+#             */
/*   Updated: 2016/12/01 21:43:38 by nbond            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*newlink;

	newlink = (t_list*)malloc(sizeof(t_list));
	if (!content)
	{
		newlink->content = NULL;
		newlink->content_size = 0;
		newlink->next = NULL;
		return (newlink);
	}
	if (newlink)
	{
		newlink->content = ft_memalloc(content_size);
		if (!newlink->content)
			return (NULL);
		newlink->content = ft_memcpy(newlink->content, content, content_size);
		newlink->content_size = content_size;
		newlink->next = NULL;
	}
	else
		return (NULL);
	return (newlink);
}
