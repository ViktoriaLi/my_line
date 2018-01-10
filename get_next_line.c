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
#include <stdio.h>

char *if_next(char **line, char **tmp, char **next_str, int *fd)
{
	int i;

	i = 0;
	while ((*next_str)[i] != '\n' && (*next_str)[i] != '\0')
		i++;
	if ((*next_str)[i] == '\n')
	{
		*line = ft_strsub((*next_str),  0, i);
		if (i != (int)ft_strlen((*next_str)))
			(*next_str) = ft_strsub((*next_str), i + 1, ft_strlen((*next_str)) - i);
		else
		{
			if ((*next_str))
				ft_strdel(next_str);
			*fd = 0;
		}
	}
	else
	{
		(*tmp) = ft_strjoin((*tmp), (*next_str));
		ft_strdel(next_str);
		*fd = 0;
	}
	return (*line);
}

int		get_next_line(const int fd, char **line)
{
	int		i;
	int		j;
	int		ret;
	char	buf[BUFF_SIZE + 1];
	char	*tmp;
	char 	*tmp2;
	static	t_list all_fd[12288];

	j = 0;
	tmp = "";
	if (fd < 0 || !line || read(fd, buf, 0) < 0 || BUFF_SIZE < 1)
	{
		return (-1);
	}
	*line = NULL;
	ret = 1;
	while (j < 12288)
	{
		if (fd == all_fd[j].fd_mem)
			if (all_fd[j].next)
				if (if_next(line, &tmp, &all_fd[j].next, &all_fd[j].fd_mem))
					return (1);
		j++;
	}
	if (j == 12288)
	{
		j = 0;
		while (all_fd[j].fd_mem)
			j++;
		all_fd[j].fd_mem = fd;
	}
	while (ret > 0)
	{
		ret = read(fd, &buf, BUFF_SIZE);
		buf[ret] = 0;
		if (ret == 0)
		{
			if (tmp[0] != 0)
			{
				*line = ft_strsub(tmp, 0, ft_strlen(tmp));
				return (1);
			}
			else
				return (ret);
		}
		if (ret > 0)
		{
			i = 0;
			while (i < ret && buf[i] != '\n')
				i++;
			if (buf[i] == '\n' || (i == ret && i != BUFF_SIZE))
			{
				tmp2 = ft_strsub(buf, 0, i);
				tmp = ft_strjoin(tmp, tmp2);
				ft_strdel(&tmp2);
				if (i != ret)
					all_fd[j].next = ft_strsub(buf, i + 1, ret - i - 1);
				else
				{
					if (all_fd[j].next)
						ft_strdel(&all_fd[j].next);
					all_fd[j].fd_mem = 0;
				}
				*line = ft_strsub(tmp, 0, ft_strlen(tmp));
				return (1);
			}
			else
			{
				if (*line)
					ft_strdel(line);
				tmp = ft_strjoin(tmp, buf);
			}
		}
	}
	return (0);
}
