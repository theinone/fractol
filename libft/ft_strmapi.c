/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enissine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 12:52:05 by enissine          #+#    #+#             */
/*   Updated: 2019/11/04 11:54:32 by enissine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*res;
	unsigned int	i;

	i = 0;
	if (!s || !(res = (char*)malloc(sizeof(char) * ft_strlen((char*)s) + 1)))
		return (NULL);
	while (s[i])
	{
		res[i] = (char)f(i, (char)s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
