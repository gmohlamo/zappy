/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 17:01:16 by gmohlamo          #+#    #+#             */
/*   Updated: 2018/05/25 15:08:14 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t		itr;
	size_t		len;
	size_t		len2;
	size_t		start;

	itr = 0;
	len2 = 0;
	len = ft_strlen(src);
	start = ft_strlen(dest);
	while (dest[itr] && itr < size)
		itr++;
	if (itr < size)
	{
		while (src[len2] && len2 < ((size - 1) - itr))
		{
			dest[start + len2] = src[len2];
			len2++;
		}
		dest[start + len2] = '\0';
	}
	return (len + itr);
}
