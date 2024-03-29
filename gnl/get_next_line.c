#include "get_next_line.h"

static int	ft_is_a_line(int fd, char **buf, char **line)
{
	char	*temp;
	size_t	len;

	len = 0;
	while (buf[fd][len] != '\n' && buf[fd][len] != '\0')
		len++;
	if (buf[fd][len] == '\n')
	{
		*line = ft_strsub(buf[fd], 0, len);
		if (!(*line))
			return (-1);
		temp = ft_strdup(buf[fd] + len + 1);
		if (!temp)
			return (-1);
		free(buf[fd]);
		buf[fd] = temp;
		if (buf[fd][0] == '\0')
			ft_strdel(&buf[fd]);
	}
	else if (buf[fd][len] == '\0')
	{
		*line = ft_strdup(buf[fd]);
		ft_strdel(&buf[fd]);
	}
	return (1);
}

int	get_next_line(const int fd, char **line)
{
	static char	*str[MAX_FD];
	char		buf[BUFF_SIZE + 1];
	char		*temp;
	int			bytes;

	if (fd < 0 || !line)
		return (-1);
	bytes = read(fd, buf, BUFF_SIZE);
	while (bytes > 0)
	{
		buf[bytes] = '\0';
		if (str[fd] == NULL)
			str[fd] = ft_strnew(1);
		temp = ft_strjoin(str[fd], buf);
		free(str[fd]);
		str[fd] = temp;
		if (ft_strchr(buf, '\n'))
			break ;
		bytes = read(fd, buf, BUFF_SIZE);
	}
	if (bytes < 0)
		return (-1);
	if ((bytes == 0 && str[fd] == NULL) || str[fd][0] == '\0')
		return (0);
	return (ft_is_a_line(fd, str, line));
}
