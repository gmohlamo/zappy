/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 18:17:42 by gmohlamo          #+#    #+#             */
/*   Updated: 2020/01/03 22:50:43 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zappy.h>

void				take_op(t_game *game, t_client *client)
{
	t_list			*lst;
	char			*item;

	lst = client->lines;
	item = ft_strchr((char*)lst->content, ' ');
	if (!item)
		send(client->fd, "ko\n", 3, MSG_DONTWAIT);
	else
		take_item(game, client, item);
	client->lines = lst->next;
	free(lst->content);
	free(lst);
	client->op = none;
	client->op_complete = true;
}