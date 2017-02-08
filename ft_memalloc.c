/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbond <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 20:27:19 by nbond             #+#    #+#             */
/*   Updated: 2016/12/01 22:22:59 by nbond            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*fresh;
	size_t	i;

	i = 0;
	fresh = malloc(size);
	if (!fresh)
		return (NULL);
	fresh = ft_memset(fresh, 0, size);
	return (fresh);
}
