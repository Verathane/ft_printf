/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbond <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 17:49:07 by nbond             #+#    #+#             */
/*   Updated: 2017/01/17 10:16:07 by nbond            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	char			*istr;
	unsigned int	i;
	int				s;

	s = 1;
	i = ft_intlen(n);
	istr = ft_strnew(i);
	if (!istr)
		return (NULL);
	if (n == 0)
		istr[0] = '0';
	if (n < 0)
	{
		istr[0] = '-';
		s = -1;
	}
	while (i && n)
	{
		istr[--i] = (s * (n % 10) + 48);
		n /= 10;
	}
	return (istr);
}
