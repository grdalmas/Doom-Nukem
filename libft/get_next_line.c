/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 21:04:04 by cmartine          #+#    #+#             */
/*   Updated: 2018/06/03 23:18:55 by cmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/* GM: Under Loonix OPEN_MAX is deprecated, set it to some "sensible" value */
#ifndef OPEN_MAX
#define OPEN_MAX FOPEN_MAX
#endif

static char		*ft_join_bufs(const int fd, char **mybuf, char **line)
{
	char	buf[BUFF_SIZE];
	char	*otherbuf;
	char	*newbuf;
	int		ret;

	ret = read(fd, buf, BUFF_SIZE);
	otherbuf = ft_strndup(buf, ret);
	newbuf = ft_strjoin(*mybuf, otherbuf);
	free(*mybuf);
	free(otherbuf);
	if (ret == 0)
	{
		if (newbuf[0] != 0)
			*line = ft_strndup(newbuf, ft_strlen(newbuf));
		ft_strdel(&newbuf);
	}
	return (newbuf);
}

static char		*ft_change_mybuf(char **mybuf, char **line, int i)
{
	char *newbuf;
	char *newbuf2;

	newbuf = ft_strndup(*mybuf, i);
	*line = ft_strdup(newbuf);
	newbuf2 = ft_strsub(*mybuf, i + 1, (ft_strlen(*mybuf) - i));
	free(*mybuf);
	free(newbuf);
	return (newbuf2);
}

static int		ft_search_lines(const int fd, char **line, char **mybuf)
{
	if (*mybuf == NULL && *line == NULL)
		return (0);
	if (ft_strchr(*mybuf, '\n') != NULL)
	{
		*mybuf = ft_change_mybuf(mybuf, line,
			(ft_strchr(*mybuf, '\n') - *mybuf));
		return (1);
	}
	else
	{
		*mybuf = ft_join_bufs(fd, mybuf, line);
		if (*mybuf == NULL && *line != NULL)
			return (1);
	}
	return (ft_search_lines(fd, line, mybuf));
}

int				get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE];
	int			ret;
	static char	*mybuf;

	if (fd < 0 || fd > OPEN_MAX || !(line) || BUFF_SIZE < 1)
		return (-1);
	if (read(fd, NULL, 0) < 0)
		return (-1);
	*line = NULL;
	if (mybuf == NULL)
	{
		ret = read(fd, buf, BUFF_SIZE);
		if (ret < 0)
			return (-1);
		if (ret == 0)
			return (0);
		if (ret > 0)
			mybuf = ft_strndup(buf, ret);
	}
	return (ft_search_lines(fd, line, &mybuf));
}
