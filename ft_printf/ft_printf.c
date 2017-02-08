/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbond <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 17:04:56 by nbond             #+#    #+#             */
/*   Updated: 2017/01/25 20:21:03 by nbond            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <stdarg.h>

int		is_flag(char c)
{
	return (ft_strchr("-+0 #", c) ? 1 : 0);
}

t_spec	*create_t_spec(void)
{
	t_spec *new_spec;

	new_spec = (t_spec*)malloc(sizeof(t_spec));
	new_spec->flags = ft_strnew(5);
	new_spec->width = 0;
	new_spec->prec = -1;
	new_spec->num = 0;
	new_spec->neg = 0;
	new_spec->length = NULL;
	return (new_spec);
}

int		handle_specifier(const char **format, va_list *ap)
{
	t_spec	*spec;
	int		len;
	char	*ptr;

	len = 0;
	ptr = NULL;
	spec = create_t_spec();
	spec = set_flags((char**)format, ptr, spec);
	spec->spec = **format;
	if (ft_strchr("OUD", spec->spec))
		spec->length = ft_strdup("l");
	if (spec->spec == '%')
		len = ft_printf_c('%', spec);
	else if (spec->spec == 's' || spec->spec == 'S')
		len = ft_printf_s(va_arg(*ap, char *), spec);
	else if (spec->spec == 'c' || spec->spec == 'C')
		len = ft_printf_c(handle_length_int(ap, spec), spec);
	else if (ft_strchr("dDi", spec->spec))
		len = ft_printf_i(handle_length_int(ap, spec), spec);
	else if (spec->spec == 'p')
		len = ft_printf_p(va_arg(*ap, void*), spec);
	else if (ft_strchr("oOuUxX", spec->spec))
		len = ft_printf_uni(handle_length_uni(ap, spec), spec);
	else
		ft_putstr("ERROR");
	return (len);
}

int		ft_printf(const char *format, ...)
{
	int		len;
	va_list	ap;

	len = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			len += handle_specifier(&format, &ap);
		}
		else
			len += write(1, format, 1);
		format++;
	}
	va_end(ap);
	return (len);
}
