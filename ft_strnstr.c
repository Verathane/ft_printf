/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbond <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:08:22 by nbond             #+#    #+#             */
/*   Updated: 2016/12/03 19:35:38 by nbond            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t len_lit;

	len_lit = (size_t)ft_strlen(big);
	len_lit = (size_t)ft_strlen(little);
	if (*little == '\0')
		return ((char*)big);
	if (len_lit > len)
		return (NULL);
	len = len - (size_t)len_lit + 1;
	while (*big && len)
	{
		len--;
		if (!ft_strncmp(big, little, len_lit))
			return ((char*)big);
		big++;
	}
	return (NULL);
}
