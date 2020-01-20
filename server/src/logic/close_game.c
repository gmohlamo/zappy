/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 15:36:05 by gmohlamo          #+#    #+#             */
/*   Updated: 2020/01/19 16:20:51 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zappy.h>

static void			clear_lines(t_client *client)
{
	t_list			*lines;
	void			*ptr;

	lines = client->lines;
	ptr = NULL;
	while (lines)
	{
		free(lines->content);
		ptr = lines;
		lines = lines->next;
		free(ptr);
	}
}

static void			close_connections(t_connection *connections)
{
	t_connection	*next;

	next = connections;
	while (next)
	{
		connections = next;
		next = next->next;
		close(connections->fd);
		free(connections);
	}
}

static void			close_game_clients(t_client *clients)
{
	t_client		*next;

	next = clients;
	while (next)
	{
		clients = next;
		next = next->next;
		clear_lines(clients);
		if (clients->fd > 0)
			close(clients->fd);
		free(clients);
	}
}

static void			close_eggs(t_egg *eggs)
{
	t_egg			*next;

	next = eggs;
	while (next)
	{
		eggs = next;
		next = next->next;
		free(eggs);
	}
}

void				close_game(t_game *game)
{
	t_client		*clients;
	t_connection	*connections;

	clients = game->clients;
	connections = game->connections;
	close_eggs(game->eggs);
	close_game_clients(clients);
	close_connections(connections);
	free(game->objects->objects);
	free(game->objects);
	free(game);
	exit(42);
}
