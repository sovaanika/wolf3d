/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 18:37:48 by bbear             #+#    #+#             */
/*   Updated: 2019/02/04 14:54:33 by bbear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*save_remain(char *str, size_t len)
{
	char	*save;
	int		len2;

	len2 = (int)ft_strlen(str) - len - 1;
	if (*str != '\0' && len2 > 0)
	{
		str += len;
		save = ft_strsub((const char *)str, 1, len2);
		str -= len;
	}
	else
		save = ft_strnew(0);
	free(str);
	return (save);
}

int			get_next_line(const int fd, char **line)
{
	static char	*tmp[4096];
	char		buf[BUFF_SIZE + 1];
	size_t		len;
	int			count;
	char		*temp;

	if (!line || fd < 0 || read(fd, buf, 0) < 0)
		return (-1);
	if (!tmp[fd])
		tmp[fd] = ft_strnew(1);
	while (!ft_strchr(tmp[fd], '\n') && (count = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[count] = '\0';
		temp = tmp[fd];
		tmp[fd] = ft_strjoin(tmp[fd], buf);
		free(temp);
	}
	if (tmp[fd] && *tmp[fd] == '\0' && !count)
		return (0);
	len = 0;
	while (tmp[fd][len] != '\n' && tmp[fd][len] != '\0')
		len++;
	*line = ft_strsub((const char *)(tmp[fd]), 0, len);
	tmp[fd] = save_remain(tmp[fd], len);
	return (1);
}
