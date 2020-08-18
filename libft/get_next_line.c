/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theinone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 13:22:35 by theinone          #+#    #+#             */
/*   Updated: 2019/11/21 13:26:06 by theinone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_outputline(char **line, char **stack, int fd)
{
	int i;

	i = 0;
	while (stack[fd][i] && stack[fd][i] != '\n')
		i++;
	if (i == 0)
	{
		if (!(*line = ft_strnew(0)))
			return (-1);
	}
	else if (i != 0)
		if (!(*line = ft_strsub(stack[fd], 0, i)))
			return (-1);
	if (i < (int)ft_strlen(stack[fd]))
	{
		if (!(ft_strcpy(stack[fd], ft_strchr(stack[fd], '\n') + 1)))
			return (-1);
	}
	else
		ft_strdel(&stack[fd]);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	int				ret;
	char			buf[BUFF_SIZE + 1];
	static char		*stack[FD_SIZE];
	char			*tmp;

	if (BUFF_SIZE < 1 || fd < 0 || line == NULL || FD_SIZE < fd)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!stack[fd])
			if (!(stack[fd] = ft_strnew(0)))
				return (-1);
		tmp = stack[fd];
		if (!(stack[fd] = ft_strjoin(tmp, buf)))
			return (-1);
		free(tmp);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	if (ret == 0 && (stack[fd] == NULL || stack[fd][0] == '\0'))
		return (0);
	return (ft_outputline(line, stack, fd));
}
