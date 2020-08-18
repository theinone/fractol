/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enissine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 11:38:48 by enissine          #+#    #+#             */
/*   Updated: 2019/10/31 13:39:22 by enissine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*phaystack;
	size_t	letters_left;
	size_t	needle_len;
	size_t	i;

	phaystack = (char *)haystack;
	if (needle[0] == '\0')
		return (phaystack);
	i = 0;
	letters_left = len;
	needle_len = (size_t)ft_strlen((char *)needle);
	while (*phaystack && letters_left >= needle_len)
	{
		if (ft_strncmp((char*)needle, phaystack, needle_len) == 0)
			return (phaystack);
		i++;
		letters_left--;
		phaystack++;
	}
	return (NULL);
}
