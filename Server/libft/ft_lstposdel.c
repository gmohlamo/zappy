/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstposdel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 17:15:04 by gmohlamo          #+#    #+#             */
/*   Updated: 2018/06/28 15:30:26 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	find_node(t_list *temp, size_t content_size)
{
	while (temp->content_size != content_size && temp != NULL)
	{
		temp = temp->next;
	}
}

void		ft_lstposdel(t_list **head, size_t content_size)
{
	t_list	*temp;
	t_list	*prev;

	temp = *head;
	prev = NULL;
	if (temp->content_size == content_size)
	{
		if (temp->next == NULL)
			ft_memdel((void*)head);
		else
		{
			prev = temp->next;
			*head = prev;
			ft_memdel((void*)temp);
		}
		return ;
	}
	find_node(temp, content_size);
	if (temp != NULL)
	{
		prev->next = temp->next;
		free(temp);
	}
}
