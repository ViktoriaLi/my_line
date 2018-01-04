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
	char	*tmp;
	char 	*tmp2;
	static	char *next_str;
	i = 0;
	j = 0;
	if (fd < 0 || !line)
		return (-1);
	tmp = "";
	buf[BUFF_SIZE] = 0;
	ret = 1;
	while (ret > 0)
	{
		if (next_str)
		{
			//printf("NEXT1 %s\n", next_str);
			i = 0;
			while (next_str[i] != '\n' && next_str[i] != '\0')
				i++;
			//printf("1EXAMPLE %s\n", *line);
			if (next_str[i] == '\n')
			{
				//printf("2EXAMPLE %s\n", *line);
				*line = ft_strsub(next_str,  0, i);
				//printf("2EXAMPLE %s\n", *line);
				next_str = ft_strsub(next_str, i + 1, ft_strlen(next_str) - i);
				break;
			}
			else
			{
				tmp = ft_strjoin(tmp, next_str);
				ft_strclr(next_str);
			}
		}
		i = 0;
		ft_strclr(buf);
		ret = read(fd, &buf, BUFF_SIZE);
		//printf("1FIRST BUF %s\n", buf);
		//printf("RET%d\n", ret);
		if (ret == -1 || ret == 0)
			return (ret);
		if (ret > 0)
		{
			while (i < ret && buf[i] != '\n')
				i++;
			if (buf[i] == '\n' || (i == ret && i != BUFF_SIZE))
			{
				//printf("III %d\n", i);
				//printf("2FIRST BUF %s\n", buf);
				tmp2 = ft_strsub(buf, 0, i);
				tmp = ft_strjoin(tmp, tmp2);
				//printf("RES %s\n", tmp);
				if (i != ret)
					next_str = ft_strsub(buf, i + 1, BUFF_SIZE - i);
				//printf("NEXT %s\n", next_str);
				*line = ft_strsub(tmp, 0, ft_strlen(tmp));
				break;
			}
			else
			{
				tmp = ft_strjoin(tmp, buf);
				//printf("ELSE TMP %s\n", tmp);
			}
		}
	}
	return (1);
}

/*#include "get_next_line.h"
#include <stdio.h>

int		get_next_line(const int fd, char **line)
{
	int		i;
	int		j;
	int		ret;
	char	buf[BUFF_SIZE + 1];
	//char	*buf;
	char	*res;
	char	*tmp;
	int k;
	static	char *next_str;
	i = 0;
	j = 0;
	if (fd < 0 || !line)
		return (-1);
	res = "";
	tmp = "";
	//buf = ft_memalloc(BUFF_SIZE + 1);
	buf[BUFF_SIZE] = 0;
	ret = 1;
	k = 2;
	while (ret > 0)
	{
		if (next_str)
		{
			//printf("NEXT1 %s\n", next_str);
			i = 0;
			while (next_str[i] != '\n' && next_str[i] != '\0')
				i++;
			//printf("1EXAMPLE %s\n", res);
			if (next_str[i] == '\n')
			{
				//printf("2EXAMPLE %s\n", res);
				res = ft_strsub(next_str,  0, i);
				//printf("2EXAMPLE %s\n", res);
				next_str = ft_strsub(next_str, i + 1, ft_strlen(next_str) - i);
				*line = res;
				ret = 1;
				break;
			}
			else
			{
				tmp = ft_strjoin(tmp, next_str);
				ft_strclr(next_str);
			}
		}
		i = 0;
		ft_strclr(buf);
		ret = read(fd, &buf, BUFF_SIZE);
		//printf("1FIRST BUF %s\n", buf);
		if (ret == -1 || ret == 0)
			return (ret);
		//if (ret == 0 && tmp != "")
		//{
		//	*line = tmp;
		//}
		while (i < BUFF_SIZE && buf[i] != '\n' && buf[i] != '\0')
			i++;
		if (buf[i] == '\n' || (i < BUFF_SIZE && buf[i] == '\0'))
		{
			//printf("2FIRST BUF %s\n", buf);
			tmp = ft_strjoin(tmp, buf);
			//printf("RES %s\n", tmp);
			next_str = ft_strsub(buf, i + 1, BUFF_SIZE - i);
			//printf("NEXT %s\n", next_str);
			i = 0;
			while (tmp[i] != '\n' && tmp[i] != '\0')
				i++;
			res = ft_strsub(tmp,  0, i);
			*line = res;
			ret = 1;
			break;
		}
		else
		{
			tmp = ft_strjoin(tmp, buf);
			//printf("ELSE TMP %s\n", tmp);
		}

	}
	return (ret);
}*/
