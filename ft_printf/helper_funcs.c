/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbond <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 21:34:37 by nbond             #+#    #+#             */
/*   Updated: 2017/01/26 23:33:27 by nbond            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_specifier(char c)
{
	return (ft_strchr("sScCdDipoOuUxX%", c) ? 1 : 0);
}

char	*set_pad(int len, t_spec *spec)
{
	char	*pad;
	int		i;

	i = 0;
	pad = ft_strnew(len);
	while (i < len)
	{
		if (spec->flags[2])
			pad[i++] = '0';
		else
			pad[i++] = ' ';
	}
	return (pad);
}

int		handle_flags(char *str, t_spec *spec)
{
	char	*pad;

	pad = ft_strnew(0);
	if (spec->prec >= 0 && (int)ft_strlen(str) > spec->prec)
		str[spec->prec] = '\0';
	if (spec->width > 0 && (int)ft_strlen(str) < spec->width)
		pad = set_pad(spec->width - ft_strlen(str), spec);
	if (spec->flags[0])
		str = ft_strjoin(str, pad);
	else
		str = ft_strjoin(pad, str);
	if (spec->flags[4] && spec->flags[2] && spec->num)
	{
		if (spec->spec == 'x')
			str = ft_strjoin("0x", str);
		else if (spec->spec == 'X')
			str = ft_strjoin("0X", str);
		else if (spec->spec == 'o')
			str = ft_strjoin("0", str);
	}
	if (spec->flags[1] && spec->flags[2] && !spec->neg)
		str = ft_strjoin("+", str);
	if (spec->flags[2] && spec->neg)
		str = ft_strjoin("-", str);
	ft_putstr(str);
	return (ft_strlen(str));
}

char	*set_flag(char *flags, char flag)
{
	if (flag == '-')
		flags[0] = '-';
	else if (flag == '+')
		flags[1] = '+';
	else if (flag == '0')
		flags[2] = '0';
	else if (flag == ' ')
		flags[3] = ' ';
	else if (flag == '#')
		flags[4] = '#';
	if (flags[0])
		flags[2] = '\0';
	if (flags[1])
		flags[3] = '\0';
	return (flags);
}

t_spec	*set_flags(char **format, char *ptr, t_spec *spec, va_list *ap)
{
	ptr = *format;
	while (!is_specifier(*ptr))
	{
		if (is_flag(*ptr))
			spec->flags = set_flag(spec->flags, *ptr++);
		else if (is_length(*ptr))
			spec->length = set_length(*format, &ptr);
		else if ((ft_isdigit(*ptr) && *ptr != '0') || *ptr == '*')
		{
			if (*ptr == '*')
				spec->width = va_arg(*ap, int);
			else
				spec->width = ft_atoi(ptr);
			while (ft_isdigit(*ptr) || *ptr == '*')
				ptr++;
		}
		else if (*ptr == '.')
		{
			if (*(++ptr) == '*')
				spec->prec = va_arg(*ap, int);
			else
				spec->prec = ft_atoi(ptr);
			while (ft_isdigit(*ptr) || *ptr == '*')
				ptr++;
		}
		else
			ptr++;
	}
	*format = ptr;
	return (spec);
}
