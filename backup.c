/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlikhotk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 13:15:46 by vlikhotk          #+#    #+#             */
/*   Updated: 2017/12/22 13:15:50 by vlikhotk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*d_temp;
	unsigned char	*s_temp;

	i = 0;
	d_temp = NULL;
	s_temp = NULL;
	if (n != 0)
	{
		d_temp = (unsigned char *)dst;
		s_temp = (unsigned char *)src;
		while (i < n)
		{
			d_temp[i] = s_temp[i];
			i++;
		}
		dst = (void *)d_temp;
	}
	return (dst);
}

void	*ft_memalloc(size_t size)
{
	size_t			i;
	unsigned char	*dest;

	i = 0;
	dest = NULL;
	if (!(dest = malloc(sizeof(unsigned char) * size)))
		return (NULL);
	while (i < size)
	{
		dest[i] = 0;
		i++;
	}
	return (dest);
}

char	*memory_increase(int *k, char *buf, int i)
{
	char *tmp;

	tmp = NULL;
	(*k) *= 2;
	tmp = ft_memalloc((*k) * BUFF_SIZE);
	ft_memcpy(tmp, buf, i);
	free(buf);
	buf = tmp;
	return (buf);
}

int		make_string(char *buf, int ret, int fd, char **line)
{
	int		i;
	int		k;
	char	*res;

	i = 1;
	k = 1;
	res = NULL;
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
	int		ret;
	char	*buf;

	if (fd < 0 || fd == 2)
		return (-1);
	buf = NULL;
	buf = ft_memalloc(BUFF_SIZE);
	ret = read(fd, &buf[0], 1);
	if (ret == -1 || ret == 0)
		return (ret);
	ret = make_string(buf, ret, fd, line);
	if (ret == 0)
		ret = 1;
	return (ret);
}
