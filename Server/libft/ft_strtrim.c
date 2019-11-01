/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 08:37:58 by gmohlamo          #+#    #+#             */
/*   Updated: 2018/05/27 12:52:09 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		start_white(char const *s)
{
	size_t			itr;

	itr = 0;
	if (s == NULL)
		return (0);
	while ((s[itr] == '\n' || s[itr] == ' ' ||
				s[itr] == '\t') && (s[itr] != '\0'))
		itr++;
	return (itr);
}

static size_t		end_white(char const *s)
{
	size_t			itr;
	size_t			end_size;

	itr = ft_strlen(s) - 1;
	end_size = 0;
	if (s == NULL)
		return (0);
	while ((s[itr] == '\n' || s[itr] == ' ' || s[itr] == '\t') && (itr > 0))
	{
		end_size++;
		itr--;
	}
	return (end_size);
}

char				*ft_strtrim(char const *s)
{
	char			*str;
	size_t			start;
	size_t			len;

	if (s == NULL)
		return (NULL);
	start = start_white(s);
	len = ft_strlen(&s[start]);
	str = NULL;
	if (len > end_white(s))
		str = ft_strsub(s, start, len - end_white(s));
	else
		return (ft_strnew(1));
	return (str);
}
