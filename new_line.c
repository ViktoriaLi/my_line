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

int		get_next_line(const int fd, char **line)
{
	int		i;
	int		j;
	int		ret;
	char	buf[BUFF_SIZE + 1];
	char	*res;
	char	*tmp;
	static	char *next_str;
	i = 0;
	j = 0;
	if (fd < 0 || fd == 2)
		return (-1);
	//printf("%d\n", 123);
	//buf = ft_memalloc(BUFF_SIZE + 1);
	buf[BUFF_SIZE] = 0;
	ret = read(fd, &buf, BUFF_SIZE);
	if (ret == -1 || ret == 0)
		return (ret);
	tmp = ft_memalloc(BUFF_SIZE + 1);
	while (buf[i] != '\n')
	{
		while (i < BUFF_SIZE && buf[i] != '\n')
		{
			if (buf[i] == '\n')
			{
				res = ft_memalloc(i);
				ft_memcpy(res, buf, i);
				*line = res;
				if (ret == 0)
					ret = 1;
				next_str = ft_strsub(buf, i + 1, BUFF_SIZE - i);
				printf("NEXT %s\n", next_str);
			}
			else
			{
				res = ft_memalloc(BUFF_SIZE);
				ft_memcpy(res, buf, i);
			}

		}
		i++;
	}

	return (ret);
}


int		get_next_line(const int fd, char **line)
{
	int		i;
	int		j;
	int		ret;
	char	buf[BUFF_SIZE + 1];
	char	*res;
	static	char *next_str;
	i = 0;
	j = 0;
	if (fd < 0 || fd == 2)
		return (-1);
	//printf("%d\n", 123);
	//buf = ft_memalloc(BUFF_SIZE + 1);
	buf[BUFF_SIZE] = 0;
	ret = read(fd, &buf, BUFF_SIZE);
	if (ret == -1 || ret == 0)
		return (ret);
	while (i < BUFF_SIZE && buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
	{
		res = ft_memalloc(i);
		ft_memcpy(res, buf, i);
		*line = res;
		if (ret == 0)
			ret = 1;
		next_str = ft_strsub(buf, i + 1, BUFF_SIZE - i);
		printf("NEXT %s\n", next_str);
	}
	return (ret);
}
