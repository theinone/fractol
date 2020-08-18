/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enissine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 14:28:15 by enissine          #+#    #+#             */
/*   Updated: 2019/11/04 12:39:47 by enissine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*res;
	int		i;

	i = 0;
	if (!s || !len || s[start] == '\0')
		return (NULL);
	if (!(res = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while ((int)len > i)
	{
		res[i] = (char)s[start];
		i++;
		start++;
	}
	res[i] = '\0';
	return (res);
}
