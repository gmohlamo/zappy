/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 08:44:48 by gmohlamo          #+#    #+#             */
/*   Updated: 2018/05/25 15:12:47 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	itr;

	itr = 0;
	while (src[itr] != '\0' && itr < n)
	{
		dest[itr] = src[itr];
		itr++;
	}
	while (itr < n)
	{
		dest[itr] = '\0';
		itr++;
	}
	return (dest);
}
