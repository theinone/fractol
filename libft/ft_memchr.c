/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enissine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 15:40:12 by enissine          #+#    #+#             */
/*   Updated: 2019/10/18 10:12:20 by enissine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned const char *ptr;

	ptr = (unsigned const char*)s;
	while (n > 0)
	{
		if (*ptr == (unsigned char)c)
		{
			return ((void*)ptr);
		}
		ptr++;
		n--;
	}
	return (0);
}
