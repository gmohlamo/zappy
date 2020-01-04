/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   see_block.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 09:45:09 by gmohlamo          #+#    #+#             */
/*   Updated: 2020/01/04 10:27:00 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zappy.h>

static void		get_resources(t_game *game, t_client *client, char **str, int x, int y)
{
	char		buffer[1024];
	t_objects	*objects;
	size_t		itr;

	itr = 0;
	ft_bzero(buffer, 1024);
	objects = game->objects;
	while (objects->count > itr)
	{
		if (objects->objects[itr].x == x && objects->objects[itr].y == y)
		{
			sprintf(buffer, "\"%s\"", resources[objects->objects[itr].type]);
			add_json_array(str, buffer);
			ft_bzero(buffer, 1024);
		}
		itr++;
	}
}

static void		get_clients(t_game *game, t_client *client, char **str, int x, int y)
{
	char		buffer[1024];
	char		*temp;
	t_client	*clients;

	temp = NULL;
	ft_bzero(buffer, 1024);
	clients = game->clients;
	while (clients)
	{
		if (clients != client && clients->x == x &&clients->y == y)
		{
			sprintf(buffer, "\"client %zu %s %zu %zu\"", clients->nbr,
				clients->team->name, clients->level, client->orientation);//object we need to put in the array for this block
			add_json_array(str, buffer);
			ft_bzero(buffer, 1024);
		}
		clients = clients->next;
	}
}

/*
** see_block()
** see the contents of the specified block
*/

char			*see_block(t_game *game, t_client *client, int x, int y)
{
	char		*str;
	char		*start = "[ ";
	char		*end = "]";

	str = NULL;
	get_clients(game, client, &str, x, y);
	get_resources(game, client, &str, x, y);
	array_end(&str);
}