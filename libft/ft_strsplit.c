/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enissine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 15:25:33 by enissine          #+#    #+#             */
/*   Updated: 2019/10/23 14:36:26 by enissine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count(char const *s, char c)
{
	size_t count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

static int		ln(const char *str, char c)
{
	int count;

	count = 0;
	while (*str != c && *str)
	{
		count++;
		str++;
	}
	return (count);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**res;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (!s || (!(res = (char**)malloc(sizeof(char*) * (count(s, c) + 1)))))
		return (NULL);
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
		{
			if (!(res[j] = (char *)malloc(sizeof(char) * (ln(s, c) + 1))))
				return (NULL);
			while (*s && *s != c)
				res[j][i++] = (char)*s++;
			res[j][i] = '\0';
			j++;
			i = 0;
		}
	}
	res[j] = NULL;
	return (res);
}
