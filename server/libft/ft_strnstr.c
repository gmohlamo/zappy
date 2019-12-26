/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 13:23:13 by gmohlamo          #+#    #+#             */
/*   Updated: 2018/05/27 10:30:03 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_match(const char *field, const char *str,
		const char *lim)
{
	size_t			itr;

	itr = 0;
	if ((field + ft_strlen(str)) > lim)
		return (0);
	while (str[itr] != '\0')
	{
		if (str[itr] != field[itr])
			return (0);
		itr++;
	}
	return (1);
}

char				*ft_strnstr(const char *haystack, const char *needle,
		size_t len)
{
	char			*ptr;
	char			*lim;
	size_t			itr;

	itr = 0;
	ptr = (char*)haystack;
	lim = (char*)(haystack + len);
	if (!needle[0])
		return (ptr);
	while (itr < len && *ptr)
	{
		if (*ptr == *needle)
			if (ft_match(ptr, needle, lim))
				return (ptr);
		ptr++;
		itr++;
	}
	return (NULL);
}
