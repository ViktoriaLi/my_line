#include "get_next_line.h"

char	*memory_increase(int *k, char *buf, int i)
{
	char *tmp;

	tmp = NULL;
	(*k) *= 2;
	tmp = ft_memalloc(BUFF_SIZE * (*k));
	ft_memcpy(tmp, buf, i);
	free(buf);
	buf = tmp;
	return (buf);
}

int		make_string(char *buf, int ret, int fd, char **line)
{
	int i;
	int k;
	char *res;

	i = 1;
	k = 1;
	while (buf[i - 1] != '\n' && ret == 1)
	{
		if (i == BUFF_SIZE * k)
			buf = memory_increase(&k, buf, i);
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

int		get_next_line(const int fd, char **line)
{
	int ret;
	char *buf;

	buf = NULL;
	buf = ft_memalloc(BUFF_SIZE);
	if (fd < 0 || fd == 2)
		return (-1);
	ret = read(fd, &buf[0], 1);
	if (ret == -1)
		return (ret);
	if (ret == 1)
	{
		ret = make_string(buf, ret, fd, line);
		if (ret == 0)
			ret = 1;
	}
	return (ret);
}
