/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbond <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 18:35:46 by nbond             #+#    #+#             */
/*   Updated: 2017/01/25 20:22:59 by nbond            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*to_hex(unsigned long n)
{
	char			*hex_str;
	int				len;
	unsigned long	tmp;

	len = ft_baselen(n, 16) + 2;
	tmp = n;
	hex_str = ft_strnew(len);
	if (!hex_str)
		return (NULL);
	hex_str = ft_strcat(hex_str, "0x");
	while (len >= 2)
	{
		tmp = n % 16;
		if (tmp <= 9)
			hex_str[len] = tmp + 48;
		else if (tmp <= 15)
			hex_str[len] = tmp + 87;
		n /= 16;
		len--;
	}
	return (hex_str);
}

int		ft_printf_p(void *ptr, t_spec *spec)
{
	char			*hex;
	unsigned long	address;

	address = (unsigned long)ptr;
	hex = to_hex(address);
	spec->prec = -1;
	return (handle_flags(hex, spec));
}
