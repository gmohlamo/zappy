/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_link_see.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 13:12:31 by gmohlamo          #+#    #+#             */
/*   Updated: 2020/01/06 14:20:54 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zappy.h>

/*
** next_link()
** just adds to the next link in a linked list
*/

void				next_link_see(t_list *lst, int *block, size_t size)
{
	t_list			*ptr;

	ptr = lst;
	while(ptr->next)
		ptr = ptr->next;
	ptr->next = ft_lstnew(block, size);
}