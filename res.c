Working with some leaks

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
	if (fd < 0 || fd > FD_LIMIT || BUFF_SIZE < 1 || BUFF_SIZE > STACK_LIMIT ||
		!line || read(fd, buf, 0) < 0)
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

Devided
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

int			reading(int fd, char **line, t_list *all_fd, int j, char **tmp)
{
	int		i;
	int		ret;
	char	buf[BUFF_SIZE + 1];
	char	*tmp2;

	i = 0;
	while ((ret = read(fd, &buf, BUFF_SIZE)) > 0)
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
	if (*tmp[0] != 0)
	{
		*line = *tmp;
		return (1);
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
	return (reading(fd, line, all_fd, j, &tmp));
}


Working

#include "get_next_line.h"

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
		return (-1);
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
	while ((ret = read(fd, &buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = 0;
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
			*line = tmp;
			return (1);
		}
		else
			tmp = ft_strjoin(tmp, buf);
	}
	if (tmp[0] != 0)
	{
		*line = tmp;
		return (1);
	}
	return (0);
}



Попытка убрать из некста непечатные символы
int		get_next_line(const int fd, char **line)
{
	int		i;
	int		j;
	int		ret;
	char	buf[BUFF_SIZE + 1];
	char	*tmp;
	char 	*tmp2;
	static	char *next_str;

	/*printf("POINTER %p\n", &i);
	printf("POINTER %p\n", &ret);
	printf("POINTER %p\n", buf);
	printf("POINTER %p\n", tmp);
	printf("POINTER %p\n", tmp2);
	printf("POINTER %p\n", next_str);
	printf("POINTER %p\n", &fd);
	printf("POINTER %p\n", *line);*/

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
			printf("NEXT1 %s\n", next_str);
			i = 0;
			while (next_str[i] != '\n' && ft_isprint(next_str[i]) && next_str[i] != '\0')
				i++;
			printf("III %d\n", i);
			printf("1EXAMPLE %s\n", *line);
			if (next_str[i] == '\n' || !ft_isprint(next_str[i]))
			{
				printf("2EXAMPLE %s\n", *line);
				*line = ft_strsub(next_str,  0, i);

				//printf("POINTER %p\n", *line);
				printf("2EXAMPLE %s\n", *line);
				j = 0;
				if (ft_isprint(next_str[i]) && ft_isprint(next_str[i + 1]))
				{
					i++;
					j = i;
					while (ft_isprint(next_str[i]))
						j++;
					next_str = ft_strsub(next_str, i, j - i);
					return (1);
					//printf("POINTER %p\n", next_str);
				}
				else
				{
					if (next_str)
						free(next_str);

				}
				//return (0);

			}
			else
			{
				tmp = ft_strjoin(tmp, next_str);
				//printf("POINTER %p\n", tmp);
				ft_strclr(next_str);
			}
		}
		i = 0;
		ft_strclr(buf);
		ret = read(fd, &buf, BUFF_SIZE);
		printf("1FIRST BUF %s\n", buf);
		printf("RET%d\n", ret);

		/*if (ret == 0 && !next_str)
		{
			printf("RES RET%d\n", ret);
			return (ret);
		}*/
		if (ret == 0)
		{
			printf("RES RET%d\n", 0);
			return (0);
		}

		//if (ret == 0)
			//continue;
		while (i < ret && buf[i] != '\n')
			i++;
		if (buf[i] == '\n' || (i == ret && i != BUFF_SIZE))
		{
			printf("III %d\n", i);
			printf("2FIRST BUF %s\n", buf);
			tmp2 = ft_strsub(buf, 0, i);
			//printf("POINTER %p\n", tmp2);
			tmp = ft_strjoin(tmp, tmp2);
			*line = ft_strsub(tmp, 0, ft_strlen(tmp));
			//printf("POINTER %p\n", tmp);
			free(tmp2);
			printf("RES %s\n", tmp);
			if (i != ret && ft_isprint(buf[i + 1]))
			{
					next_str = ft_strsub(buf, i + 1, ret - i - 1);
					printf("NEXT %s\n", next_str);
				//printf("POINTER %p\n", next_str);
			}
			else
				if (next_str)
					free(next_str);

			printf("RES RET%d\n", 1);
			//printf("POINTER %p\n", *line);
			return (1);
		}
		else
		{
			tmp = ft_strjoin(tmp, buf);
			//printf("POINTER %p\n", tmp);
			printf("ELSE TMP %s\n", tmp);
		}
	}
	printf("RES RET%d\n", 0);
	return (0);
}



#include "get_next_line.h"
#include <stdio.h>
работает но не под весь сайз и без фри
int		get_next_line(const int fd, char **line)
{
	int		i;
	int		j;
	int		ret;
	char	buf[BUFF_SIZE + 1];
	char	*res;
	char	*tmp;
	int k;
	static	char *next_str;
	i = 0;
	j = 0;
	if (fd < 0 || fd == 2)
		return (-1);
	res = "";
	tmp = "";
	buf[BUFF_SIZE] = 0;
	ret = 1;
	k = 1;
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
		if (ret == -1 || (ret == 0 && tmp == ""))
			return (ret);
		/*if (ret == 0 && tmp != "")
		{
			*line = tmp;
		}*/
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
			break;
		}
		else
		{
			tmp = ft_strjoin(tmp, buf);
			//printf("ELSE TMP %s\n", tmp);
		}
		if (ret == 0)
			ret = 1;
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
	char	*tmp;
	static	char *next_str;
	i = 0;
	j = 0;
	if (fd < 0 || fd == 2)
		return (-1);
	//printf("%d\n", 123);
	//buf = ft_memalloc(BUFF_SIZE + 1);
	//res = NULL;
	//tmp = "\0";
	//res = "\0";
	//next_str = "";
	res = "";
	tmp = "";
	//res = NULL;
	//next_str = NULL;
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
			//printf("LEN1 %d\n", i);
			//printf("1EXAMPLE %s\n", res);
			if (next_str[i] == '\n')
			{
				//printf("2EXAMPLE %s\n", res);
				res = ft_strsub(next_str,  0, i);
				//printf("3EXAMPLE %s\n", res);
				next_str = ft_strsub(next_str, i + 1, ft_strlen(next_str) - i);
				*line = res;
				return (ret);
			}
			else
				tmp = ft_strjoin(tmp, next_str);
		}
		i = 0;
		ft_strclr(buf);
		ret = read(fd, &buf, BUFF_SIZE);
		//printf("1FIRST BUF %s\n", buf);
		if (ret == -1 || ret == 0)
			return (ret);
		while (i < BUFF_SIZE && buf[i] != '\n' && buf[i] != '\0')
			i++;
		if (buf[i] == '\n' || (i < BUFF_SIZE && buf[i] == '\0'))
		{
			//printf("2FIRST BUF %s\n", buf);
			//tmp = ft_strjoin(tmp, buf);
			tmp = ft_strjoin(tmp, buf);
			//tmp = ft_strncat(tmp, buf, i);
			//printf("RES %s\n", tmp);
			next_str = ft_strsub(buf, i + 1, BUFF_SIZE - i);
			//printf("LEN %d\n", BUFF_SIZE - i);
			//printf("NEXT %s\n", next_str);
			i = 0;
			while (tmp[i] != '\n' && tmp[i] != '\0')
				i++;
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
			//printf("ELSE TMP %s\n", tmp);
			ft_strclr(buf);
			//ret = read(fd, &buf, BUFF_SIZE);
		}
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
		if (next_str)
		{
			while (next_str[i] != '\n' && (next_str[i] != '\0'))
				i++;
			if (next_str[i])
		}
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
		if (next_str)
		{
			while (next_str[i] != '\n' && (next_str[i] != '\0'))
				i++;
			if (next_str[i] == '\n')
			{
				res = ft_strsub(next_str,  0, i);
				next_str = ft_strsub(buf, i + 1, BUFF_SIZE - i);
				*line = res;
				return (ret);
			}

		}
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
