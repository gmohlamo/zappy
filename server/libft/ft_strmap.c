/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 12:04:55 by gmohlamo          #+#    #+#             */
/*   Updated: 2018/05/27 12:23:47 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char c))
{
	char	*str;
	size_t	itr;

	if (!s || !f)
		return (NULL);
	if ((str = ft_strnew(ft_strlen(s))) == NULL)
		return (NULL);
	itr = 0;
	while (s[itr] != '\0')
	{
		str[itr] = f(s[itr]);
		itr++;
	}
	return (str);
}
