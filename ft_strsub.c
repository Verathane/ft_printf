/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbond <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 23:23:27 by nbond             #+#    #+#             */
/*   Updated: 2016/12/03 18:49:30 by nbond            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*newstr;

	i = 0;
	if (!s)
		return (NULL);
	while (i++ < start)
		s++;
	i = 0;
	newstr = ft_strnew(len);
	if (!newstr)
		return (NULL);
	while (i < len)
		newstr[i++] = *s++;
	return (newstr);
}
