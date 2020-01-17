/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level_up_client.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 09:38:40 by gmohlamo          #+#    #+#             */
/*   Updated: 2020/01/16 14:16:12 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zappy.h>

/*
** level_up_clients()
** upgrades client levels up to the level provided
*/

bool			level_up_client(t_game *game, t_client *client, size_t level_cap)
{
	t_client	*clients;
	char		buffer[1024];

	ft_bzero(buffer, sizeof(buffer));
	clients = game->clients;
	while (clients)
	{
		if (clients->x == client->x && clients->y == clients->y &&
			clients->level < level_cap)
		{
			if (client != clients)
			{
				sprintf(buffer, "level_up %zu\n", clients->level + 1);
				send(clients->fd, buffer, ft_strlen(buffer), MSG_DONTWAIT);
				ft_bzero(buffer, sizeof(buffer));
			}
			clients->level++;
		}
		clients = clients->next;
	}
	return (true);
}