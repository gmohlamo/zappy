/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 17:14:28 by gmohlamo          #+#    #+#             */
/*   Updated: 2018/05/23 11:49:45 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*ptr;

	ptr = *alst;
	del(ptr->content, ptr->content_size);
	free(ptr);
	*alst = NULL;
}
