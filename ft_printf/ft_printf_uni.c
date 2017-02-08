/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uni.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbond <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 09:54:08 by nbond             #+#    #+#             */
/*   Updated: 2017/01/25 20:21:39 by nbond            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*to_lower(char *str)
{
	char *head;

	head = str;
	while (*str)
	{
		*str = ft_tolower(*str);
		str++;
	}
	return (head);
}

char	*ft_uintmaxtoa(uintmax_t n)
{
	char			*str;
	unsigned int	i;

	i = ft_baselen(n, 10);
	str = ft_strnew(i);
	if (!str)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	while (i && n)
	{
		str[--i] = (n % 10) + 48;
		n /= 10;
	}
	return (str);
}

char	*ft_uintmaxtoa_base(uintmax_t value, int base)
{
	char		*str;
	int			i;
	uintmax_t	rem;

	i = ft_baselen(value, base);
	str = (char*)malloc(sizeof(char) * i--);
	if (base == 10 || value < 2)
		return (ft_uintmaxtoa(value));
	while (value > 0)
	{
		rem = value % (uintmax_t)base;
		value /= (uintmax_t)base;
		if (rem > 9)
			str[i--] = rem + 55;
		else
			str[i--] = rem + 48;
	}
	return (str);
}

#include <stdio.h>
int		ft_printf_uni(uintmax_t i, t_spec *spec)
{
	char	*str = NULL;

	spec->num = 1;
	if (spec->spec == 'o' || spec->spec == 'O')
		str = ft_uintmaxtoa_base(i, 8);
	else if (spec->spec == 'u' || spec->spec == 'U')
		str = ft_uintmaxtoa(i);
	else if (spec->spec == 'x' || spec->spec == 'X')
		str = ft_uintmaxtoa_base(i, 16);
	if ((int)ft_strlen(str) < spec->prec || spec->prec == 0)
		spec->flags[2] = '\0';
	if (i == 0 && spec->prec >= 0)
	{
		str[0] = '\0';
		spec->num = 0;
	}
	if ((int)ft_strlen(str) < spec->prec)
		str = num_pad(str, spec);
	if (spec->flags[4] && !spec->flags[2] && ft_strchr("xX", spec->spec) && i)
		str = ft_strjoin("0X", str);
	else if (spec->flags[4] && !spec->flags[2] && ft_strchr("oO", spec->spec))
		str = ft_strjoin("0", str);
	else if (spec->flags[4] && ft_strchr("xX", spec->spec))
		spec->width -= 2;
	else if (spec->flags[4] && ft_strchr("oO", spec->spec))
		spec->width -= 1;
	if (spec->spec == 'o' || spec->spec == 'x')
		str = to_lower(str);
	spec->prec = -1;
	return (handle_flags(str, spec));
}