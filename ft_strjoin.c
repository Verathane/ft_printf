/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbond <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 15:38:57 by nbond             #+#    #+#             */
/*   Updated: 2016/12/03 18:50:06 by nbond            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *newstr;

	if (!s1 || !s2)
		return (NULL);
	newstr = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (!newstr)
		return (NULL);
	newstr = ft_strcpy(newstr, s1);
	newstr = ft_strcat(newstr, s2);
	return (newstr);
}
