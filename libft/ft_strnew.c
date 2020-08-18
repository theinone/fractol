/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enissine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 12:15:35 by enissine          #+#    #+#             */
/*   Updated: 2019/10/30 13:16:57 by enissine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*ptr;
	int		i;

	i = 0;
	if (!(ptr = (char*)malloc(sizeof(char) * size + 1)))
		return (NULL);
	while ((size_t)i < size)
	{
		ptr[i] = '\0';
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
