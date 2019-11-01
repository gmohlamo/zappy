/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 16:41:57 by gmohlamo          #+#    #+#             */
/*   Updated: 2018/05/25 13:33:11 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*node;

	if ((node = ft_memalloc(sizeof(t_list))) == NULL)
		return (NULL);
	if (content == NULL)
	{
		node->content = NULL;
		node->content_size = 0;
	}
	else
	{
		if ((node->content = ft_memalloc(content_size)) == NULL)
		{
			free(node);
			return (NULL);
		}
		node->content = ft_memmove(node->content, (void*)content, content_size);
		node->content_size = content_size;
	}
	node->next = NULL;
	return (node);
}
