/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 10:26:16 by gmohlamo          #+#    #+#             */
/*   Updated: 2018/05/27 11:42:50 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_countwords(char const *s, char delim)
{
	size_t			itr;
	size_t			count;

	itr = 0;
	count = 0;
	while (s[itr] != '\0')
	{
		if (s[itr] == delim)
			while (s[itr] == delim)
				itr++;
		else
		{
			count++;
			while (s[itr] != '\0' && s[itr] != delim)
				itr++;
		}
	}
	return (count);
}

static size_t		between_size(char const *s, char delim)
{
	size_t			len;

	len = 0;
	while (s[len] != delim && s[len] != '\0')
		len++;
	return (len);
}

static char			**ft_pointto(char const *s, char **ptrs, char delim,
		size_t count)
{
	size_t			itr1;
	size_t			itr2;

	itr1 = 0;
	itr2 = 0;
	if ((ptrs = malloc(sizeof(char*) * (count + 1))) == NULL)
		return (NULL);
	ptrs[count] = NULL;
	while (s[itr1] != '\0' && count)
	{
		while (s[itr1] == delim)
			itr1++;
		ptrs[itr2] = ft_strsub(&s[itr1], 0, between_size(&s[itr1], delim));
		itr2++;
		while (s[itr1] != delim && s[itr1] != '\0')
			itr1++;
		count--;
	}
	return (ptrs);
}

char				**ft_strsplit(char const *s, char c)
{
	char			**strs;
	size_t			count;

	if (s == NULL)
		return (NULL);
	strs = NULL;
	count = ft_countwords(s, c);
	strs = ft_pointto(s, strs, c, count);
	return (strs);
}
