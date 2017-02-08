/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbond <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 22:50:12 by nbond             #+#    #+#             */
/*   Updated: 2016/12/03 00:19:29 by nbond            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_strlcat(char *dst, char *src, size_t size)
{
	size_t	i;
	size_t	l;
	size_t	len_d;

	i = 0;
	len_d = ft_strlen(dst);
	l = len_d;
	if (l > size)
		return (size + ft_strlen(src));
	while (src[i] && l < size - 1)
		dst[l++] = src[i++];
	dst[l] = '\0';
	return (len_d + ft_strlen(src));
}
