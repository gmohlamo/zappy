/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 08:44:56 by gmohlamo          #+#    #+#             */
/*   Updated: 2018/05/25 13:40:41 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	char			*dst;
	char			*sr;

	i = 0;
	dst = (char*)dest;
	sr = (char*)src;
	if (dest > src)
	{
		while (n)
		{
			dst[n - 1] = sr[n - 1];
			n--;
		}
	}
	else
	{
		while (i < n)
		{
			dst[i] = sr[i];
			i++;
		}
	}
	return (dest);
}
