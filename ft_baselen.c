/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_baselen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbond <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 11:46:23 by nbond             #+#    #+#             */
/*   Updated: 2017/02/06 11:30:47 by nbond            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_baselen(uintmax_t n, int base)
{
	int i;

	i = 0;
	if (n == 0)
		i++;
	while (n != 0)
	{
		n /= (uintmax_t)base;
		i++;
	}
	return (i);
}
