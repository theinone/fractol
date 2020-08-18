/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enissine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 13:48:51 by enissine          #+#    #+#             */
/*   Updated: 2019/11/04 11:15:12 by enissine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char			*ptr;
	const unsigned char		*ptr2;
	int						i;

	if (!dst && !src)
		return (NULL);
	i = 0;
	ptr = (unsigned char *)dst;
	ptr2 = (unsigned char *)src;
	while (n > 0)
	{
		ptr[i] = ptr2[i];
		i++;
		n--;
	}
	return (dst);
}
