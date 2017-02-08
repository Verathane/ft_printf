/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbond <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 19:07:48 by nbond             #+#    #+#             */
/*   Updated: 2017/02/08 12:41:04 by nbond            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_intmaxlen(intmax_t n)
{
	int i;

	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_imaxtoa(intmax_t n)
{
	char			*str;
	unsigned int	i;
	int				s;

	s = 1;
	i = ft_intmaxlen(n);
	str = ft_strnew(i);
	if (!str)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		s = -1;
	}
	while (n != 0)
	{
		str[--i] = (s * (n % 10) + 48);
		n /= 10;
	}
	return (str);
}

char	*num_pad(char *str, t_spec *spec)
{
	char	*pad;
	int		len;

	len = spec->prec - ft_strlen(str);
	pad = ft_strnew(len);
	while (len--)
		pad[len] = '0';
	str = ft_strjoin(pad, str);
	return (str);
}

int		ft_printf_i(intmax_t i, t_spec *spec)
{
	char	*str;

	spec->num = 1;
	str = ft_imaxtoa(i);
	if (i < 0)
		str = &(str[1]);
	spec->neg = (i < 0 ? 1 : 0);
	if ((int)ft_strlen(str) < spec->prec || spec->prec >= 0)
		spec->flags[2] = '\0';
	if (spec->prec == 0 && i == 0)
		str = ft_strdup("\0");
	if ((int)ft_strlen(str) < spec->prec)
		str = num_pad(str, spec);
	if (i >= 0 && spec->flags[1] && !spec->flags[2])
		str = ft_strjoin("+", str);
	if (i < 0 && !spec->flags[2])
		str = ft_strjoin("-", str);
	if (((i >= 0 && spec->flags[1]) || i < 0) && spec->flags[2])
		spec->width -= 1;
	if (i < 0)
		spec->flags[3] = '\0';
	if (spec->flags[3] && !spec->flags[1])
		str = ft_strjoin(" ", str);
	spec->prec = -1;
	return (handle_flags(str, spec));
}
