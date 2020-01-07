/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kick.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 18:17:29 by gmohlamo          #+#    #+#             */
/*   Updated: 2020/01/03 22:49:39 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zappy.h>

static void			kick_member(t_game *game, t_client *client)
{
	if (client->orientation == 0)
		client->y = client->y - 1 >= 0? client->y - 1: game->y - 1;
	else if (client->orientation == 1)
		client->x = (client->x + 1) % game->x;
	else if (client->orientation == 2)
		client->y = (client->y + 1) % game->y;
	else
		client->x = client->x - 1 >= 0? client->x - 1: game->x - 1;
	update_gfx(game, client);
}

void				kick_op(t_game *game, t_client *client)
{
	t_list				*lst;
	t_client			*clients;

	clients = game->clients;	
	while (clients)
	{
		if (client != clients && clients->x == client->x &&
			clients->y == client->y)
			kick_member(game, clients);
		clients = clients->next;
	}
	lst = client->lines;
	client->lines = lst->next;
	free(lst->content);
	free(lst);
	send(client->fd, "ok\n", 3, MSG_DONTWAIT);
	client->op = none;
	client->op_complete = true;
}