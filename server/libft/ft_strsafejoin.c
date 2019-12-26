/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsafejoin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 12:01:52 by gmohlamo          #+#    #+#             */
/*   Updated: 2018/06/18 12:01:54 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsafejoin(char *s1, char *s2)
{
	char	*temp;

	temp = NULL;
	if (s1 == NULL)
	{
		if (s2 == NULL)
			return (ft_strnew(0));
		s1 = ft_strnew(0);
		temp = ft_strjoin(s1, s2);
		ft_strdel(&s1);
		return (temp);
	}
	else if (s2 == NULL)
	{
		s2 = ft_strnew(0);
		temp = ft_strjoin(s1, s2);
		ft_strdel(&s2);
		return (temp);
	}
	else
		return (ft_strjoin(s1, s2));
}
