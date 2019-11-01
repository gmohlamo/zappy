/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 08:44:35 by gmohlamo          #+#    #+#             */
/*   Updated: 2018/05/25 10:50:13 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			itr;
	unsigned char	*x;
	unsigned char	*y;

	itr = 0;
	x = (unsigned char*)dest;
	y = (unsigned char*)src;
	while (itr < n)
	{
		x[itr] = y[itr];
		itr++;
	}
	dest = (void*)x;
	return (dest);
}
