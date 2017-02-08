/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbond <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 20:52:05 by nbond             #+#    #+#             */
/*   Updated: 2016/11/30 20:39:51 by nbond            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*fresh;
	size_t	i;

	i = 0;
	fresh = (char*)malloc(sizeof(char) * (size + 1));
	if (!fresh)
		return (NULL);
	while (i <= size)
		fresh[i++] = '\0';
	return (fresh);
}
