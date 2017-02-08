/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbond <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 15:46:25 by nbond             #+#    #+#             */
/*   Updated: 2016/12/03 21:19:18 by nbond            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strrchr(const char *s, int c)
{
	int i;

	i = 0;
	if (!*s && c == '\0')
		return ((char*)s);
	if (!*s)
		return (NULL);
	while (*s)
	{
		i++;
		s++;
	}
	while (*s != (char)c && i >= 0)
	{
		i--;
		s--;
	}
	if (i == -1)
		return (NULL);
	return ((char*)s);
}
