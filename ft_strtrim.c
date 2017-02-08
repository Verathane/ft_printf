/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbond <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 16:10:07 by nbond             #+#    #+#             */
/*   Updated: 2016/12/03 18:51:45 by nbond            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*ptr;
	char	*newstr;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	while (ft_iswhitespace(*s))
		s++;
	ptr = (char*)s;
	while (ptr[i])
		i++;
	if (*s)
		i--;
	while (ft_iswhitespace(ptr[i]) && i > 0)
		i--;
	newstr = ft_strnew(i + 1);
	if (!newstr)
		return (NULL);
	while (i >= 0)
	{
		newstr[i] = ptr[i];
		i--;
	}
	return (newstr);
}
