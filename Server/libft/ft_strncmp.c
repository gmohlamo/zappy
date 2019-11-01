/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 13:51:43 by gmohlamo          #+#    #+#             */
/*   Updated: 2018/05/25 15:12:13 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	itr;

	itr = 0;
	while ((*s1 != '\0' || *s2 != '\0') && (itr < n))
	{
		if (*s1 != *s2)
			break ;
		itr++;
		s1++;
		s2++;
	}
	if (itr == n)
		return (0);
	return (*(const unsigned char*)s1 - *(const unsigned char*)s2);
}
