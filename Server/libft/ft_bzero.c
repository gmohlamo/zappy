/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bzero.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 08:43:14 by gmohlamo          #+#    #+#             */
/*   Updated: 2018/05/25 13:35:26 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_bzero(void *s, size_t n)
{
	unsigned char	*str;
	size_t			itr;

	itr = 0;
	str = (unsigned char*)s;
	while (itr < n)
	{
		str[itr] = 0;
		itr++;
	}
	s = (void*)str;
	return (s);
}
