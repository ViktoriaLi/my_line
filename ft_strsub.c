/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlikhotk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:06:57 by vlikhotk          #+#    #+#             */
/*   Updated: 2017/11/08 13:07:00 by vlikhotk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*dest;

	i = 0;
	dest = NULL;
	if (!s)
		return (NULL);
	if (!(dest = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (len != 0)
	{
		while (i < len)
		{
			dest[i] = (char)s[start];
			i++;
			start++;
		}
		dest[i] = 0;
	}
	return (dest);
}
