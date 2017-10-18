/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeaun-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 10:42:10 by cmeaun-a          #+#    #+#             */
/*   Updated: 2017/05/04 23:31:52 by cmeaun-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_fd		*multi_fd(const int fd, t_fd **tmp)
{
	if (!*tmp)
	{
		if (!(*tmp = (t_fd*)malloc(sizeof(t_fd))))
			return (NULL);
		(*tmp)->fd = fd;
		(*tmp)->buff = "";
		(*tmp)->next = NULL;
		return (*tmp);
	}
	if ((*tmp)->fd == fd)
		return (*tmp);
	return (multi_fd(fd, &((*tmp)->next)));
}

int			ft_len(char *line)
{
	int		i;

	if (!line)
		return (-1);
	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

void		get_line(char **line, t_fd *tmp)
{
	if (ft_len(*line) > -1)
	{
		tmp->buff = ft_strsub(*line, ft_len(*line) + 1, ft_strlen(*line)
				- ft_len(*line) - 1);
		*line = ft_strsubf(*line, 0, ft_len(*line));
	}
	else
		tmp->buff = "";
}

int			get_next_line(const int fd, char **line)
{
	int				ret;
	char			buff[BUFF_SIZE + 1];
	t_fd			*tmp;
	static t_fd		*stock = NULL;

	ret = 1;
	if (!line || fd < 0)
		return (-1);
	tmp = multi_fd(fd, &stock);
	*line = ft_strdup(tmp->buff);
	while (ret && ft_len(*line) == -1)
	{
		ret = read(fd, buff, BUFF_SIZE);
		if (ret == -1)
			return (-1);
		buff[ret] = '\0';
		*line = ft_strjoinf(*line, buff);
	}
	get_line(line, tmp);
	free(*line);
	if (!ret && !**line && !tmp->buff[0])
		return (0);
	return (1);
}
