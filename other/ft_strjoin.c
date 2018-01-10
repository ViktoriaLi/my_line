/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlikhotk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:07:10 by vlikhotk          #+#    #+#             */
/*   Updated: 2017/11/08 13:07:13 by vlikhotk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*copy_strings(char const *s1, char const *s2, char *fs1)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i] != 0)
	{
		fs1[i] = (char)s1[i];
		i++;
	}
	while (s2[j] != 0)
	{
		fs1[i] = (char)s2[j];
		i++;
		j++;
	}
	fs1[i] = 0;
	return (fs1);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*fs1;

	i = 0;
	j = 0;
	fs1 = NULL;
	if (s1 == NULL)
		return (NULL);
	if (s2 == NULL)
		return (char *)(s1);
	fs1 = (char *)s1;
	while (fs1[i] != 0)
		i++;
	while (s2[j] != 0)
		j++;
	if (!(fs1 = malloc((j + i + 1))))
		return (NULL);
	return (copy_strings(s1, s2, fs1));
}
