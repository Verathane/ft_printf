/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbond <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 07:31:39 by nbond             #+#    #+#             */
/*   Updated: 2016/12/10 07:34:25 by nbond            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnstr(char const *s, unsigned int len)
{
	unsigned int i;

	i = 0;
	if (!s)
		return ;
	while (i < len)
		write(1, &(s[i++]), 1);
}
