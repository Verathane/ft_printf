/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbond <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 22:14:34 by nbond             #+#    #+#             */
/*   Updated: 2016/12/03 18:43:35 by nbond            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*fresh;
	unsigned int	index;

	index = 0;
	if (!s || !f)
		return (NULL);
	fresh = ft_strnew((unsigned int)ft_strlen(s));
	if (!fresh)
		return (NULL);
	while (*s)
	{
		fresh[index] = f(index, *s++);
		index++;
	}
	return (fresh);
}
