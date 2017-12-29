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
	//res = NULL;
	tmp = "\0";
	res = "\0";
	next_str = "\0";
	buf[BUFF_SIZE] = 0;
	ret = read(fd, &buf, BUFF_SIZE);
	printf("1FIRST BUF %s\n", buf);
	if (ret == -1 || ret == 0)
		return (ret);
	while (ret > 0)
	{
			i = 0;
			while (i < BUFF_SIZE && buf[i] != '\n' && buf[i] != '\0')
				i++;
			if (buf[i] == '\n' || (i < BUFF_SIZE && buf[i] == '\0'))
			{
				printf("2FIRST BUF %s\n", buf);
				//tmp = ft_strjoin(tmp, buf);
				tmp = ft_strjoin(tmp, buf);
				//tmp = ft_strncat(tmp, buf, i);
				printf("RES %s\n", tmp);
				next_str = ft_strsub(buf, i + 1, BUFF_SIZE - i);
				printf("NEXT %s\n", next_str);
				i = 0;
				while (tmp[i] != '\n' && tmp[i] != '\0')
					i++;
				printf("LEN %d\n", i);
				res = ft_strsub(tmp,  0, i);
				//ft_memcpy(res, buf, i);
				*line = res;
				break;
				/*if (ret == 0)
					ret = 1;*/
			}
			else
			{
				tmp = ft_strjoin(tmp, buf);
				printf("ELSE TMP %s\n", tmp);
				ft_strclr(buf);
				ret = read(fd, &buf, BUFF_SIZE);
			}
	}
	return (ret);
}

/*int		get_next_line(const int fd, char **line)
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
}*/
