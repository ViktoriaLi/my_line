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
	//buf = NULL;
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
		//free(buf);
		*line = res;
		if (ret == 0)
			ret = 1;
		next_str = ft_strsub(buf, ++i, BUFF_SIZE - i + 1);
	}
	return (ret);
}
