/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 10:54:41 by gmohlamo          #+#    #+#             */
/*   Updated: 2018/06/29 10:40:52 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrev(char *str)
{
	char	*temp;
	size_t	itr;
	size_t	len;

	len = ft_strlen(str);
	itr = 0;
	if ((temp = ft_strnew(len)) == NULL)
		return (NULL);
	len--;
	while (itr < ft_strlen(str))
	{
		temp[itr] = str[len - itr];
		itr++;
	}
	ft_strdel(&str);
	str = temp;
	return (temp);
}
