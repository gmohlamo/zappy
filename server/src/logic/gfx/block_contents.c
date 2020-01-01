/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_contents.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 12:45:52 by gmohlamo          #+#    #+#             */
/*   Updated: 2020/01/01 13:17:09 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zappy.h>
#include <gfx.h>

static char		*add_orientation(char *str, size_t orientation)
{
	char		*temp;
	char		*temp2;

	temp = ft_strjoinint(str, orientation);
	temp2 = ft_strjoin(temp, " ");
	free(temp);
	return (temp2);
}

//sends client information in the block to the gfx
static char		*send_client(t_game *game, char **gfx_line, t_client *client)
{
	char		*str;
	char		*temp;

	str = ft_strdup("client ");
	temp = ft_strjoinint(str, client->nbr);
	free(str);
	str = ft_strjoin(temp, " ");
	free(temp);
	temp = ft_strjoin(str, client->team->name);
	free(str);
	str = ft_strjoin(temp, " ");
	free(temp);
	temp = ft_strjoinint(str, client->level);
	free(str);
	str = add_orientation(temp, client->orientation);
	free(temp);
	temp = str;
	str = ft_strjoin(temp, "\n");
	free(temp);
	concat_gfx_line(gfx_line, str);
	return (*gfx_line);
}

bool			send_clients(t_game *game, char **gfx_line, t_client *clients, int x, int y)
{
	size_t		count;
	char		*str;

	str = NULL;
	count = 0;
	while (clients)
	{
		if (clients->x == x && clients->y == y)
			str = send_client(game, gfx_line, clients);
		clients = clients->next;
	}
	if (str)
	{
		concat_gfx_line(gfx_line, str);
		return (true);
	}
	return (false);
}

/*
** send_objects()
** should append to the gfx_str the objects in the string
*/

bool			send_objects(t_game *game, char **gfx_str, int x, int y)
{
	t_objects	*objects;
	char		*str;
	char		buffer[64];
	size_t		count;
	size_t		itr;

	itr = 0;
	objects = game->objects;
	ft_bzero(buffer, 64);
	str = NULL;
	count = 0;
	while (itr < objects->count)
	{
		if (objects->objects[itr].x == x &&
			objects->objects[itr].y == y)
		{
			sprintf(buffer, "resource %d\n", objects->objects[itr].type);
			if (!str)
				str = ft_strdup(buffer);
			else
				concat_resource(&str, buffer);
			count++;
		}
		itr++;
	}
	if (str)
		concat_gfx_line(gfx_str, str);
	return (count > 0? true : false);
}

char			*block_contents(t_game *game, int x, int y)
{
	char		**gfx_str;
	char		*str;
	t_client	*clients;

	gfx_str = ft_memalloc(sizeof(char**));
	clients = game->clients;
	send_objects(game, gfx_str, x, y);
	send_clients(game, gfx_str, clients, x, y);
	send_eggs(game, gfx_str, x, y);
	str = *gfx_str;
	return (str);
}