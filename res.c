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
