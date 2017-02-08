/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbond <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 20:47:13 by nbond             #+#    #+#             */
/*   Updated: 2016/12/03 14:26:09 by nbond            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	len = 0;
	while (s1[len])
		len++;
	str = (char*)malloc(sizeof(*s1) * (len + 1));
	if (!str)
	{
		errno = ENOMEM;
		return (NULL);
	}
	while (i <= len)
	{
		str[i] = s1[i];
		i++;
	}
	str[len + 1] = '\0';
	return (str);
}
