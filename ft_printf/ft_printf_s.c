/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbond <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 15:49:30 by nbond             #+#    #+#             */
/*   Updated: 2017/01/25 20:17:00 by nbond            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_s(char *str, t_spec *spec)
{
	int		len;

	str = ft_strdup(str);
	len = handle_flags(str, spec);
	free(str);
	return (len);
}
