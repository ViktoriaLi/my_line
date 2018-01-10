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

char		*if_next(char **line, char **tmp, char **next_s, int *fd)
{
	int i;

	i = 0;
	while ((*next_s)[i] != '\n' && (*next_s)[i] != '\0')
		i++;
	if ((*next_s)[i] == '\n')
	{
		*line = ft_strsub((*next_s), 0, i);
		if (i != (int)ft_strlen((*next_s)))
			(*next_s) = ft_strsub((*next_s), i + 1, ft_strlen((*next_s)) - i);
		else
		{
			if ((*next_s))
				ft_strdel(next_s);
			*fd = 0;
		}
	}
	else
	{
		(*tmp) = ft_strjoin((*tmp), (*next_s));
		ft_strdel(next_s);
		*fd = 0;
	}
	return (*line);
}

int			find_fd(int fd, char **line, t_list *all_fd, char **tmp)
{
	int		j;
	char	*buf;

	j = 2;
	buf = NULL;
	if (fd < 0 || !line || read(fd, buf, 0) < 0 || BUFF_SIZE < 1)
		return (-1);
	*line = NULL;
	while (j < 12290)
	{
		if (fd == all_fd[j].fd_mem)
			if (all_fd[j].next)
				if (if_next(line, tmp, &all_fd[j].next, &all_fd[j].fd_mem))
					return (1);
		j++;
	}
	if (j == 12290)
	{
		j = 2;
		while (all_fd[j].fd_mem)
			j++;
		all_fd[j].fd_mem = fd;
	}
	return (j);
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

int			reading(char **line, t_list *all_fd, int j, char **tmp)
{
	int		i;
	int		ret;
	char	buf[BUFF_SIZE + 1];
	char	*tmp2;

	while ((ret = read(all_fd[j].fd_mem, &buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = 0;
		i = 0;
		while (i < ret && buf[i] != '\n')
			i++;
		if (buf[i] == '\n' || (i == ret && i != BUFF_SIZE))
		{
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
		}
		else
			*tmp = ft_strjoin(*tmp, buf);
	}
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	int							j;
	char						*tmp;
	static t_list		all_fd[12290];

	tmp = "";
	j = find_fd(fd, line, all_fd, &tmp);
	if (j == 1 || j == -1)
		return (j);
	j = reading(line, all_fd, j, &tmp);
	if (tmp[0] != 0)
	{
		*line = tmp;
		return (1);
	}
	return (j);
}
