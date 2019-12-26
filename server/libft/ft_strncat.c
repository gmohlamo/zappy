/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 08:44:57 by gmohlamo          #+#    #+#             */
/*   Updated: 2018/05/25 15:10:55 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	len;
	size_t	itr;

	itr = 0;
	len = ft_strlen(dest);
	while (itr < n && src[itr] != '\0')
	{
		dest[len + itr] = src[itr];
		itr++;
	}
	dest[len + itr] = '\0';
	return (dest);
}
