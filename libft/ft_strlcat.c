/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enissine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 13:12:49 by enissine          #+#    #+#             */
/*   Updated: 2019/10/23 15:35:24 by enissine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t s1;
	size_t s2;
	size_t size;

	size = dstsize;
	s1 = (size_t)ft_strlen((char*)dst);
	s2 = (size_t)ft_strlen((char*)src);
	i = 0;
	if (size == 0)
		return (s2);
	if (size <= s1)
		return (s2 + size);
	while (src[i] && s1 + i < size - 1)
	{
		dst[s1 + i] = src[i];
		i++;
	}
	dst[s1 + i] = '\0';
	return (s1 + s2);
}
