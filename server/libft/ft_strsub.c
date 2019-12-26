/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 07:56:59 by gmohlamo          #+#    #+#             */
/*   Updated: 2018/05/27 12:41:59 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	itr1;
	size_t	itr2;

	itr1 = start;
	itr2 = 0;
	if (s != NULL)
	{
		if (start > ft_strlen(s))
			return (NULL);
		if (ft_strlen(&s[start]) < len)
			return (NULL);
		if ((str = ft_strnew(sizeof(char) * (len))) == NULL)
			return (NULL);
		while (itr2 < len && s[itr1] != '\0')
		{
			str[itr2] = s[itr1];
			itr1++;
			itr2++;
		}
		return (str);
	}
	return (NULL);
}
