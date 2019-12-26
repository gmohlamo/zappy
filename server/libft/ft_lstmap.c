/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 11:13:56 by gmohlamo          #+#    #+#             */
/*   Updated: 2018/05/25 17:46:40 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*ptr;
	t_list	*head;
	t_list	*holder;

	ptr = NULL;
	head = NULL;
	holder = NULL;
	if (lst)
		if ((ptr = f(lst)) == NULL)
			return (NULL);
	head = ptr;
	holder = head;
	while (lst)
	{
		lst = lst->next;
		if (lst == NULL)
			break ;
		ptr = f(lst);
		holder->next = ptr;
		holder = holder->next;
	}
	return (head);
}
