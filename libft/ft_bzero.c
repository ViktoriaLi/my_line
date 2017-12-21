/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlikhotk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 18:00:32 by vlikhotk          #+#    #+#             */
/*   Updated: 2017/10/31 18:00:43 by vlikhotk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*d;

	i = 0;
	d = NULL;
	if (n != 0)
	{
		d = (unsigned char *)s;
		while (i < n)
		{
			d[i] = 0;
			i++;
		}
		s = (void *)d;
	}
}