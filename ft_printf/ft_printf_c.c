/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbond <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 22:16:36 by nbond             #+#    #+#             */
/*   Updated: 2017/01/25 19:59:59 by nbond            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_c(intmax_t c, t_spec *spec)
{
	char	*pad;
	int		len;

	pad = ft_strnew(0);
	if (spec->width > 1)
		pad = set_pad(spec->width - 1, spec);
	spec->flags[0] ? ft_putchar((int)c) : ft_putstr(pad);
	spec->flags[0] ? ft_putstr(pad) : ft_putchar((int)c);
	len = ft_strlen(pad) + 1;
	free(pad);
	return (len);
}
