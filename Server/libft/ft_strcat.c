/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 08:45:47 by gmohlamo          #+#    #+#             */
/*   Updated: 2018/05/25 13:54:00 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strcat(char *dest, const char *src)
{
	size_t	itr;
	size_t	len;

	itr = 0;
	len = ft_strlen(dest);
	while (src[itr] != '\0')
	{
		dest[len + itr] = src[itr];
		itr++;
	}
	dest[len + itr] = '\0';
	return (dest);
}
