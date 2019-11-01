/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 08:43:31 by gmohlamo          #+#    #+#             */
/*   Updated: 2018/05/25 13:37:12 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			itr;
	unsigned char	*x;
	unsigned char	*y;

	itr = 0;
	x = (unsigned char*)dest;
	y = (unsigned char*)src;
	while (itr < n)
	{
		if (y[itr] == (unsigned char)c)
		{
			x[itr] = y[itr];
			itr++;
			return ((void*)&x[itr]);
		}
		x[itr] = y[itr];
		itr++;
	}
	dest = (void*)src;
	return (NULL);
}
