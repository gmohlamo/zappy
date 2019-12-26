/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 17:42:34 by gmohlamo          #+#    #+#             */
/*   Updated: 2018/05/25 15:36:29 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_match(const char *field, const char *str)
{
	size_t			itr;

	itr = 0;
	while (str[itr] != '\0')
	{
		if (str[itr] != field[itr])
			return (0);
		itr++;
	}
	return (1);
}

char				*ft_strstr(const char *haystack, const char *needle)
{
	char			*ptr;

	ptr = (char*)haystack;
	if (!ft_strlen(needle))
		return (ptr);
	while (*ptr != '\0')
	{
		if (*ptr == *needle)
			if (ft_match(ptr, needle))
				return (ptr);
		ptr++;
	}
	return (NULL);
}
