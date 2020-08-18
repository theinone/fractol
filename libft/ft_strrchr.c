/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enissine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 10:06:13 by enissine          #+#    #+#             */
/*   Updated: 2019/10/23 15:40:05 by enissine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int count;

	count = 0;
	while (*s)
	{
		count++;
		++s;
	}
	if (c == '\0')
		return ((char*)s);
	while (count >= 0)
	{
		if (*s == c)
		{
			return ((char*)s);
		}
		count--;
		s--;
	}
	return (0);
}
