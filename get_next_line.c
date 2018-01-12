/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlikhotk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 13:24:07 by vlikhotk          #+#    #+#             */
/*   Updated: 2018/01/11 17:49:08 by vlikhotk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*if_next(char **line, char **tmp, char **next_s, int i)
{
	char	*rem;

	rem = NULL;
	while ((*next_s)[i] != '\n' && (*next_s)[i] != '\0')
		i++;
	if ((*next_s)[i] == '\n')
	{
		*line = ft_strsub((*next_s), 0, i);
		if (i != (int)ft_strlen((*next_s)) && (*next_s)[i + 1])
		{
			rem = (*next_s);
			(*next_s) = ft_strsub((*next_s), i + 1, ft_strlen((*next_s)) - i);
			ft_strdel(&rem);
		}
		else
		{
			if ((*next_s))
				ft_strdel(next_s);
		}
	}
	else
	{
		rem = (*tmp);
		(*tmp) = ft_strjoin((*tmp), (*next_s));
		ft_strdel(next_s);
		if (rem[0])
			ft_strdel(&rem);
	}
	return (*line);
}

int		if_n_found(char *buf, char **tmp, int ret, char **all_fd)
{
	int		i;
	char	*rem;
	char	*swap;

	i = 0;
	buf[ret] = 0;
	rem = NULL;
	swap = NULL;
	while (i < ret && buf[i] != '\n')
		i++;
	if (buf[i] == '\n' || (i == ret && i != BUFF_SIZE))
	{
		if (i > 0)
			rem = ft_strsub(buf, 0, i);
		if (rem)
		{
			swap = *tmp;
			*tmp = ft_strjoin(*tmp, rem);
			if (swap[0])
				ft_strdel(&swap);
			ft_strdel(&rem);
		}
		if ((ret - i - 1) > 0)
		{
			rem = *all_fd;
			*all_fd = ft_strsub(buf, i + 1, ret - i - 1);
			ft_strdel(&rem);
			if (i == ret)
				ft_strdel(all_fd);
		}
		return (1);
	}
	return (0);
}

int		reading(char **line, char **all_fd, char **tmp, int fd)
{
	int		ret;
	char	buf[BUFF_SIZE + 1];
	char	*swap;

	swap = NULL;
	while ((ret = read(fd, &buf, BUFF_SIZE)) > 0)
	{
		if (if_n_found(buf, tmp, ret, &all_fd[fd]))
		{
			*line = *tmp;
			return (1);
		}
		else
		{
			swap = *tmp;
			*tmp = ft_strjoin(swap, buf);
			if (swap[0])
				ft_strdel(&swap);
		}
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	int					res;
	char				*tmp;
	char				*buf;
	static char			*all_fd[FD_LIMIT];

	res = 0;
	tmp = "";
	buf = NULL;
	if (fd < 0 || !line || read(fd, buf, 0) < 0 || BUFF_SIZE < 1 ||
		fd > FD_LIMIT)
		return (-1);
	*line = NULL;
	if (all_fd[fd])
		if (if_next(line, &tmp, &all_fd[fd], res))
			return (1);
	res = reading(line, all_fd, &tmp, fd);
	if (tmp[0] != 0)
	{
		*line = tmp;
		return (1);
	}
	return (res);
}
