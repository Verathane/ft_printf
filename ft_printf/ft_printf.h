/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbond <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 00:10:50 by nbond             #+#    #+#             */
/*   Updated: 2017/02/09 13:45:42 by nbond            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft.h"
# include <stdarg.h>

typedef struct	s_spec
{
	char	*flags;
	int		width;
	int		prec;
	char	*length;
	char	spec;
	int		num;
	int		neg;
}				t_spec;

intmax_t		handle_length_int(va_list *ap, t_spec *spec);
uintmax_t		handle_length_uni(va_list *ap, t_spec *spec);
t_spec			*create_t_spec(void);
t_spec			*set_flags(char **format, char *ptr, t_spec *spec, va_list *ap);
char			*set_pad(int len, t_spec *spec);
char			*num_pad(char *str, t_spec *spec);
char			*set_length(char *str);
char			*ft_imaxtoa(intmax_t n);
char			*to_lower(char *str);
int				is_length(char c);
int				is_specifier(char c);
int				is_flag(char c);
int				handle_flags(char *str, t_spec *spec);
int				ft_printf(const char *format, ...);
int				ft_printf_s(char *str, t_spec *spec);
int				ft_printf_c(intmax_t c, t_spec *spec);
int				ft_printf_i(intmax_t i, t_spec *spec);
int				ft_printf_p(void *ptr, t_spec *spec);
int				ft_printf_uni(uintmax_t i, t_spec *spec, char *str);

#endif
