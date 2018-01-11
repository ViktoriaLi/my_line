/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlikhotk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 13:24:07 by vlikhotk          #+#    #+#             */
/*   Updated: 2017/12/25 13:25:01 by vlikhotk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*if_next(char **line, char **tmp, char **next_s)
{
	int		i;
	char	*tmp2;

	i = 0;
	while ((*next_s)[i] != '\n' && (*next_s)[i] != '\0')
		i++;
	if ((*next_s)[i] == '\n')
	{
		*line = ft_strsub((*next_s), 0, i);
		if (i != (int)ft_strlen((*next_s)))
		{
			tmp2 = (*next_s);
			(*next_s) = ft_strsub((*next_s), i + 1, ft_strlen((*next_s)) - i);
			ft_strdel(&tmp2);
		}
		else
		{
			if ((*next_s))
				ft_strdel(next_s);
		}
	}
	else
	{
		(*tmp) = ft_strjoin((*tmp), (*next_s));
		ft_strdel(next_s);
	}
	return (*line);
}

/*int n_found(char *buf, char **tmp, int i, )
{
	char	*tmp2;

	tmp2 = ft_strsub(buf, 0, i);
	*tmp = ft_strjoin(*tmp, tmp2);
	ft_strdel(&tmp2);
	if (i != ret)
		all_fd[j].next = ft_strsub(buf, i + 1, ret - i - 1);
	else
	{
		if (all_fd[j].next)
			ft_strdel(&all_fd[j].next);
		all_fd[j].fd_mem = 0;
	}
	*line = *tmp;
	return (1);
}*/

int		reading(char **line, char **all_fd, char **tmp, int fd)
{
	int		i;
	int		ret;
	char	buf[BUFF_SIZE + 1];
	char	*tmp2;
	char	*b1;

	while ((ret = read(fd, &buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = 0;
		i = 0;
		while (i < ret && buf[i] != '\n')
			i++;
		if (buf[i] == '\n' || (i == ret && i != BUFF_SIZE))
		{
			tmp2 = ft_strsub(buf, 0, i);
			b1 = *tmp;
			*tmp = ft_strjoin(*tmp, tmp2);
			if (b1[0])
				free(b1);
			ft_strdel(&tmp2);
			if (i != ret)
				all_fd[fd] = ft_strsub(buf, i + 1, ret - i - 1);
			else
			{
				if (all_fd[fd])
					ft_strdel(&all_fd[fd]);
			}
			*line = *tmp;
			return (1);
		}
		else
		{
			b1 = *tmp;
			*tmp = ft_strjoin(b1, buf);
			if (b1[0])
				free(b1);
		}
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	int					j;
	char				*tmp;
	char				*buf;
	static char	*all_fd[FD_LIMIT];

	tmp = "";
	buf = NULL;
	if (fd < 0 || !line || read(fd, buf, 0) < 0 || BUFF_SIZE < 1)
		return (-1);
	*line = NULL;
	if (all_fd[fd])
		if (if_next(line, &tmp, &all_fd[fd]))
			return (1);
	j = reading(line, all_fd, &tmp, fd);
	if (tmp[0] != 0)
	{
		*line = tmp;
		return (1);
	}
	return (j);
}
