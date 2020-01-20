/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level_up_client.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 09:38:40 by gmohlamo          #+#    #+#             */
/*   Updated: 2020/01/21 00:02:51 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zappy.h>
#include <gfx.h>

/*
** level_up_clients()
** upgrades client levels up to the level provided
*/

bool			level_up_client(t_game *game, t_client *client, size_t level_cap)
{
	t_client	*clients;
	char		buffer[1024];
	char		*str;

	ft_bzero(buffer, sizeof(buffer));
	clients = game->clients;
	str = NULL;
	gfx_incantation_update(game, client, &str);
	while (clients)
	{
		if (clients->x == client->x && clients->y == clients->y &&
			clients->level < level_cap)
		{
			if (client != clients)
			{
				gfx_incantation_update(game, clients, &str);
				sprintf(buffer, "level_up %zu\n", clients->level + 1);
				send(clients->fd, buffer, ft_strlen(buffer), MSG_DONTWAIT);
				ft_bzero(buffer, sizeof(buffer));
			}
			clients->level++;
		}
		clients = clients->next;
	}
	close_incantation_update(game, &str);
	return (true);
}