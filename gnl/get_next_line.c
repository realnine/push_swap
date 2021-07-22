/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinglee <jinglee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 16:39:31 by jinglee           #+#    #+#             */
/*   Updated: 2021/04/05 14:55:10 by jinglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		cutting(char **buf_store, char **line, char *ptr_next)
{
	char *tmp;

	*ptr_next = '\0';
	if (!(*line = ft_strdup(*buf_store)))
	{
		free(*buf_store);
		return (-1);
	}
	tmp = *buf_store;
	if (!(*buf_store = ft_strdup(ptr_next + 1)))
	{
		free(tmp);
		return (-1);
	}
	free(tmp);
	return (1);
}

int		last_cutting(char **buf_store, char **line)
{
	if (*buf_store == NULL)
	{
		*line = ft_strdup("");
		return (0);
	}
	if (!(*line = ft_strdup(*buf_store)))
	{
		free(*buf_store);
		return (-1);
	}
	free(*buf_store);
	*buf_store = NULL;
	return (0);
}

int		get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*buf_store[OPEN_MAX];
	ssize_t		rtn_read;
	char		*tmp;

	if (fd > OPEN_MAX || fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	while ((rtn_read = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[rtn_read] = '\0';
		buf_store[fd] = ft_strjoin(buf_store[fd], buf);
		if ((tmp = ft_strchr(buf_store[fd], '\n')))
			return (cutting(&buf_store[fd], line, tmp));
	}
	if (rtn_read == 0)
	{
		if ((tmp = ft_strchr(buf_store[fd], '\n')))
			return (cutting(&buf_store[fd], line, tmp));
		return (last_cutting(&buf_store[fd], line));
	}
	free(buf_store[fd]);
	buf_store[fd] = NULL;
	return (-1);
}
