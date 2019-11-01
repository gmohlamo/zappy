/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 08:42:13 by gmohlamo          #+#    #+#             */
/*   Updated: 2018/05/25 14:58:23 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strcpy(char *dest, const char *src)
{
	size_t	itr;
	size_t	len;

	itr = 0;
	len = ft_strlen(src);
	while (itr <= len)
	{
		dest[itr] = src[itr];
		itr++;
	}
	return (dest);
}
