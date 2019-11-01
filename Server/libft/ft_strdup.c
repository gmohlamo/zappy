/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 13:21:25 by gmohlamo          #+#    #+#             */
/*   Updated: 2018/05/25 15:00:25 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t	len;
	char	*cpy;

	len = 0;
	cpy = NULL;
	len = ft_strlen(src);
	if ((cpy = malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	cpy = ft_strcpy(cpy, src);
	return (cpy);
}
