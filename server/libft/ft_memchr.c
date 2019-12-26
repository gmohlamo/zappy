/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 14:52:22 by gmohlamo          #+#    #+#             */
/*   Updated: 2018/05/27 10:45:32 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memchr(const void *s, int c, size_t n)
{
	size_t			itr;
	unsigned char	*x;
	unsigned char	chr;

	x = (unsigned char*)s;
	itr = 0;
	chr = c;
	while (itr < n)
	{
		if (*x == chr)
		{
			return ((void*)x);
		}
		itr++;
		x++;
	}
	return (NULL);
}
