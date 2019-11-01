/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 14:54:50 by gmohlamo          #+#    #+#             */
/*   Updated: 2018/05/27 12:23:28 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	itr;

	itr = 0;
	if (s == NULL || f == NULL)
		return ;
	while (s[itr] != '\0')
	{
		f(itr, &s[itr]);
		itr++;
	}
}
