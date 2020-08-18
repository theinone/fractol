/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enissine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 11:16:21 by enissine          #+#    #+#             */
/*   Updated: 2019/11/04 11:26:31 by enissine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	ret[11];
	char	*res;
	int		isneg;
	int		i;
	int		j;

	j = 0;
	i = 0;
	isneg = n < 0 ? -1 : 1;
	while (isneg * n > 9 || isneg * n < 0)
	{
		ret[i++] = '0' + isneg * (n % 10);
		n = n / 10;
	}
	ret[i++] = '0' + isneg * n;
	if (isneg < 0)
		ret[i++] = '-';
	if (!(res = (char *)malloc(sizeof(char) * i + 1)))
		return (NULL);
	res[i] = '\0';
	while (i--)
		res[i] = ret[j++];
	return (res);
}
