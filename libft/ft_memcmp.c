/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enissine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 15:54:10 by enissine          #+#    #+#             */
/*   Updated: 2019/11/14 10:35:47 by enissine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ptr;
	unsigned char	*ptr2;

	ptr = (unsigned char*)s1;
	ptr2 = (unsigned char*)s2;
	if (n == 0 || s1 == s2)
		return (0);
	while (n--)
	{
		if (*ptr != *ptr2)
			return ((int)(*ptr - *ptr2));
		if (n)
		{
			ptr++;
			ptr2++;
		}
	}
	return ((int)(*ptr - *ptr2));
}
