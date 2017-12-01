#include "get_next_line.h"
#include <stdio.h>

int get_next_line(const int fd, char **line)
{
	int i;
	int ret;
	int k;
	char *buf;
	char *res;
	char *tmp;

	i = 0;
	k = 1;
	buf = ft_memalloc(BUFF_SIZE);
	ret = 1;
	while (buf[i - 1] != '\n' && ret == 1)
	{
		if (i == BUFF_SIZE * k)
		{	
			k *= 2;
			tmp = ft_memalloc(BUFF_SIZE * k);
			ft_memcpy(tmp, buf, i);
			free(buf);
			buf = tmp;
		}
		ret = read(fd, &buf[i], 1);
		i++;
	}
	buf[i - 1] = 0;
	res = ft_memalloc(i);
	ft_memcpy(res, buf, i);
	*line = res;
	free(buf);
	return (ret);
}


/*	while (ret != 0)
	{
		buf = ft_memalloc(BUFF_SIZE * k);
		tmp = ft_memalloc(BUFF_SIZE * k);
		while (i < BUFF_SIZE * k && buf[i - 1] != '\n' && ret != 0)
		{
			ret = read(fd, &buf[i], 1);
			i++;
		}
		tmp = ft_memcpy(tmp, buf, i);
		free(buf);
		if (i == BUFF_SIZE * k)
		{
			
			buf = ft_memalloc(BUFF_SIZE * 2);
			buf = ft_memcpy(tmp, buf, i);
		}
		if (buf[i - 1] == '\n')
		{
			buf[i - 1] = 0;
			res = ft_memalloc(i);
			res = ft_memcpy(res, buf, i);
			line = &res;
		}
	}
	
	*/