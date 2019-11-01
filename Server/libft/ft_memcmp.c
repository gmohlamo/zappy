/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 15:05:46 by gmohlamo          #+#    #+#             */
/*   Updated: 2018/05/25 13:38:24 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			itr;
	unsigned char	*x;
	unsigned char	*y;

	itr = 0;
	x = (unsigned char*)s1;
	y = (unsigned char*)s2;
	while (itr < n)
	{
		if (x[itr] != y[itr])
			return (x[itr] - y[itr]);
		itr++;
	}
	return (0);
}
