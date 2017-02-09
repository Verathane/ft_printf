/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbond <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 22:48:05 by nbond             #+#    #+#             */
/*   Updated: 2017/02/09 13:43:52 by nbond            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

int			is_length(char c)
{
	return (ft_strchr("hljz", c) ? 1 : 0);
}

char		*set_length(char *str)
{
	if (*str == 'h' && *(str + 1) == 'h')
		return (ft_strdup("hh"));
	else if (*str == 'h')
		return (ft_strdup("h"));
	else if (*str == 'l' && *(str + 1) == 'l')
		return (ft_strdup("ll"));
	else if (*str == 'l')
		return (ft_strdup("l"));
	else if (*str == 'j')
		return (ft_strdup("j"));
	else if (*str == 'z')
		return (ft_strdup("z"));
	else
		return (0);
}

intmax_t	handle_length_int(va_list *ap, t_spec *spec)
{
	intmax_t cast;

	if (!spec->length)
		return ((cast = (int)va_arg(*ap, intmax_t)));
	else if (ft_strcmp(spec->length, "hh") == 0)
		return ((cast = (signed char)va_arg(*ap, intmax_t)));
	else if (ft_strcmp(spec->length, "h") == 0)
		return ((cast = (short)va_arg(*ap, intmax_t)));
	else if (ft_strcmp(spec->length, "ll") == 0)
		return ((cast = (long long)va_arg(*ap, intmax_t)));
	else if (ft_strcmp(spec->length, "l") == 0)
		return ((cast = (long)va_arg(*ap, intmax_t)));
	else if (ft_strcmp(spec->length, "j") == 0)
		return ((cast = (intmax_t)va_arg(*ap, intmax_t)));
	else if (ft_strcmp(spec->length, "z") == 0)
		return ((cast = (size_t)va_arg(*ap, intmax_t)));
	else
		return ((cast = 0));
}

uintmax_t	handle_length_uni(va_list *ap, t_spec *spec)
{
	uintmax_t cast;

	if (!spec->length)
		return ((cast = (unsigned int)va_arg(*ap, uintmax_t)));
	else if (ft_strcmp(spec->length, "hh") == 0)
		return ((cast = (unsigned char)va_arg(*ap, uintmax_t)));
	else if (ft_strcmp(spec->length, "h") == 0)
		return ((cast = (unsigned short)va_arg(*ap, uintmax_t)));
	else if (ft_strcmp(spec->length, "ll") == 0)
		return ((cast = (unsigned long long)va_arg(*ap, uintmax_t)));
	else if (ft_strcmp(spec->length, "l") == 0)
		return ((cast = (unsigned long)va_arg(*ap, uintmax_t)));
	else if (ft_strcmp(spec->length, "j") == 0)
		return ((cast = (uintmax_t)va_arg(*ap, uintmax_t)));
	else if (ft_strcmp(spec->length, "z") == 0)
		return ((cast = (size_t)va_arg(*ap, uintmax_t)));
	else
		return ((cast = 0));
}
