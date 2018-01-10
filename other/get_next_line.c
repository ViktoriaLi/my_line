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

# define ENDL '\n'

int	read_from_fd_into_stock(int const fd, char **stock)
{
	static char	buff[BUFF_SIZE+1] = { ENDL };
	int			read_bytes;
    char        *nstr;

	read_bytes = read(fd, buff, BUFF_SIZE);
	if (read_bytes > 0)
	{
        buff[read_bytes] = '\0';
        nstr = ft_strjoin(*stock, buff);
        if (!nstr)
            return (-1);
        free(*stock);
        *stock = nstr;
	}
	return (read_bytes);
}

int get_next_line(int const fd, char ** line)
{
	static char	*stock = NULL;
	char		*endl_index;
    int         ret;

    if (!stock && (stock = (char *)ft_memalloc(sizeof(char))) == NULL)
        return (-1);
	endl_index = ft_strchr(stock, ENDL);
	while (endl_index == NULL)
	{
        ret = read_from_fd_into_stock(fd, &stock);
        if (ret == 0)
        {
            if ( (endl_index = ft_strchr(stock, '\0')) == stock )
                return (0);
        } else if (ret < 0)
            return (-1);
        else
            endl_index = ft_strchr(stock, ENDL);
	}
    *line = ft_strsub(stock, 0, endl_index - stock);
    if (!*line)
        return (-1);
    endl_index = ft_strdup(endl_index + 1);
    free(stock);
    stock = endl_index;
	return (1);
}




/*char *if_next(char **line, char **tmp, char **next_str, int fd)
{
	int i;
	char one[2];
	int res;
	//printf("NEXT1 %s\n", *next_str);
	i = 0;
	if (*line)
	{
		free(*line);
		*line = NULL;
	}
	one[0] = 0;
	one[1] = 0;
	res = read(fd, &one[0], 1);
	while ((*next_str)[i] != '\n' && (*next_str)[i] != '\0')
		i++;
	//printf("1EXAMPLE %s\n", *line);
	if ((*next_str)[i] == '\n' || res == 0)
	{
		//printf("2EXAMPLE %s\n", *line);
		*line = ft_strsub((*next_str),  0, i);
		//printf("2EXAMPLE %s\n", *line);
		if (i != (int)ft_strlen((*next_str)))
		{
			(*next_str) = ft_strsub((*next_str), i + 1, ft_strlen((*next_str)) - i);
			if (one[0] != 0)
				(*next_str) = ft_strjoin((*next_str), one);
		}
		else
			if ((*next_str))
			{
				free((*next_str));
				(*next_str) = NULL;
			}
	}
	else
	{
		(*tmp) = ft_strjoin((*tmp), (*next_str));
		if (one[0] != 0)
			(*tmp) = ft_strjoin((*tmp), one);
		free((*next_str));
		(*next_str) = NULL;
	}
	return (*line);
}

int		get_next_line(const int fd, char **line)
{
	int		i;
	int		ret;
	char	buf[BUFF_SIZE + 1];
	char	*tmp;
	char 	*tmp2;
	static	char *next_str;

	i = 0;
	tmp = "";
	if (fd < 0 || !line || read(fd, buf, 0) < 0 || BUFF_SIZE < 1)
	{
		//printf("RES RET%d\n", -1);
		return (-1);
	}
	*line = NULL;
	ret = 1;
	if (next_str)
	{
		//printf("NEXT1 %s\n", next_str);
		if (if_next(line, &tmp, &next_str, fd))
			return (1);
	}
	while ((ret = read(fd, &buf, BUFF_SIZE)) != 0)
	{
		if (next_str)
		{
			//printf("NEXT1 %s\n", next_str);
			if (if_next(line, &tmp, &next_str, fd))
				return (1);
		}
		i = 0;
		while (i < ret && buf[i] != '\n')
			i++;
		if (buf[i] == '\n' || (i == ret && i != BUFF_SIZE))
		{
			//printf("III %d\n", i);
			//printf("1FIRST BUF %s\n", buf);
			tmp2 = ft_strsub(buf, 0, i);
			tmp = ft_strjoin(tmp, tmp2);
			free(tmp2);
			tmp2 = NULL;
			//printf("RES %s\n", tmp);
			if (i != ret)
			{
				next_str = ft_strsub(buf, i + 1, ret - i - 1);
			//	printf("NEXT %s\n", next_str);
				//printf("POINTER %p\n", next_str);
			}
			else
				if (next_str)
				{
					free(next_str);
					next_str = NULL;
				}
			//printf("NEXT %s\n", next_str);
			*line = ft_strsub(tmp, 0, ft_strlen(tmp));
			return (1);
		}
		else
		{
			if (*line)
			{
				free(*line);
				*line = NULL;
			}
			tmp = ft_strjoin(tmp, buf);
		//	printf("ELSE TMP %s\n", tmp);
		}
		ft_strclr(buf);
		//ret = read(fd, &buf, BUFF_SIZE);
	}
	if (next_str)
	{
		//printf("NEXT1 %s\n", next_str);
		if (if_next(line, &tmp, &next_str, fd))
			return (1);
	}
	return (0);
}*/

/*
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
	tmp = "";
	buf[BUFF_SIZE] = 0;
	if (fd < 0 || !line || read(fd, buf, 0) < 0)
	{
		printf("RES RET%d\n", -1);
		return (-1);
	}
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
				return (1);
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
				free(tmp2);
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
*/
