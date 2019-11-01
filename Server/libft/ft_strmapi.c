/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 21:29:44 by gmohlamo          #+#    #+#             */
/*   Updated: 2018/05/27 11:00:39 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	itr;

	itr = 0;
	if (!s || !f)
		return (NULL);
	if ((str = ft_strnew(ft_strlen(s))) == NULL)
		return (NULL);
	while (s[itr] != '\0')
	{
		str[itr] = f(itr, s[itr]);
		itr++;
	}
	return (str);
}
