/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbond <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 21:53:26 by nbond             #+#    #+#             */
/*   Updated: 2016/12/03 18:42:52 by nbond            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*fresh;
	int		index;

	index = 0;
	if (!s || !f)
		return (NULL);
	fresh = ft_strnew((unsigned int)ft_strlen(s));
	if (!fresh)
		return (NULL);
	while (*s)
		fresh[index++] = f(*s++);
	return (fresh);
}
