/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlikhotk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 13:22:56 by vlikhotk          #+#    #+#             */
/*   Updated: 2017/11/01 13:25:44 by vlikhotk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl(char const *s)
{
	int i;

	i = 0;
	if (s)
	{
		while (s[i] != 0)
		{
			write(1, &s[i], 1);
			i++;
		}
		write(1, "\n", 1);
	}
}