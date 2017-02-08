/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbond <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 10:35:02 by nbond             #+#    #+#             */
/*   Updated: 2017/01/17 15:00:49 by nbond            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(int value, int base)
{
	char	*str;
	int		i;
	int		rem;

	i = ft_baselen(value, base);
	str = (char*)malloc(sizeof(char) * i--);
	if (base == 10 || value < 2)
		return (ft_itoa(value));
	while (value > 0)
	{
		rem = value % base;
		value /= base;
		if (rem > 9)
			str[i--] = rem + 55;
		else
			str[i--] = rem + 48;
	}
	return (str);
}
