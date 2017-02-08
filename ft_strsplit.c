/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbond <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 16:54:32 by nbond             #+#    #+#             */
/*   Updated: 2016/12/03 18:51:13 by nbond            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_words(const char *str, char c)
{
	int		total;

	total = 0;
	while (str[total] != c && str[total])
		total++;
	if (!str[total])
		return (0);
	total = 0;
	while (*str)
	{
		while (*str == c && *str)
			str++;
		while (*str != c && *str)
			str++;
		total++;
	}
	return (total);
}

static char	**to_array(const char *str, char **str_array, int index, char c)
{
	int		len;

	len = 0;
	while (str[len] != c && str[len] != '\0')
		len++;
	str_array[index] = ft_strnew(len);
	if (!str_array[index])
		return (NULL);
	len = 0;
	while (str[len] != c && str[len] != '\0')
	{
		str_array[index][len] = str[len];
		len++;
	}
	str_array[index][len] = '\0';
	return (str_array);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**str_array;
	int		curr_word;

	curr_word = 0;
	if (!s)
		return (NULL);
	str_array = (char**)malloc(sizeof(char*) * (num_words(s, c) + 1));
	if (!str_array)
		return (NULL);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			str_array = to_array(s, str_array, curr_word++, c);
		while (*s != c && *s)
			s++;
	}
	str_array[curr_word] = NULL;
	return (str_array);
}
