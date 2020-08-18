/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enissine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 14:57:26 by enissine          #+#    #+#             */
/*   Updated: 2019/10/18 10:10:50 by enissine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char			*ptr;
	const unsigned char		*ptr2;
	int						i;

	i = 0;
	ptr = (unsigned char *)dst;
	ptr2 = (unsigned char *)src;
	while (n > 0)
	{
		ptr[i] = ptr2[i];
		if (ptr2[i] == (unsigned char)c)
		{
			return (&dst[i + 1]);
		}
		i++;
		n--;
	}
	return (0);
}
