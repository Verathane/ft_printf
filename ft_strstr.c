/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbond <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 20:35:42 by nbond             #+#    #+#             */
/*   Updated: 2016/12/02 17:39:26 by nbond            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	if (!(*little))
		return ((char*)big);
	while (*big)
	{
		if (!ft_strncmp(big, little, ft_strlen(little)))
			return ((char*)big);
		big++;
	}
	return (NULL);
}
