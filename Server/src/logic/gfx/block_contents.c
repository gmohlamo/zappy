/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_contents.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 12:45:52 by gmohlamo          #+#    #+#             */
/*   Updated: 2019/12/17 16:16:53 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zappy.h>
#include <gfx.h>

static char		*cat_resource(char *str, t_object *objects)
{
	char		*temp;
	char		*temp2;

	temp = ft_itoa(objects->type);
	temp2 = ft_strjoin(str, temp);
	free(str);
	free(temp);
	str = ft_strjoin(temp2, "\n");
	free(temp2);
	return (str);
}

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
static void		send_client(t_game *game, t_client *client, size_t index)
{
	char		*str;
	char		*temp;

	str = ft_strdup("client ");
	temp = ft_strjoinint(str, index);
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
	send(game->gfx, str, ft_strlen(str), MSG_DONTWAIT);
	free(str);
	free(temp);
}

void			send_clients(t_game *game, t_client *clients, int x, int y)
{
	size_t		count;

	count = 0;
	while (clients)
	{
		count++;
		if (clients->x == x && clients->y == y)
			send_client(game, clients, count);
		clients = clients->next;
	}
}

void			block_contents(t_game *game, int x, int y)
{
	t_client	*clients;
	t_object	*objects;
	size_t		count;
	char		*str;

	str = NULL;
	clients = game->clients;
	objects = game->objects->objects;
	count = game->objects->count;
	while (count)
	{
		if (objects->x == x && objects->y == y)
		{
			str = ft_strdup("resource ");
			str = cat_resource(str, objects);
			send(game->gfx, str, ft_strlen(str), MSG_DONTWAIT);
			free(str);
		}
		count--;
	}
	send_clients(game, clients, x, y);
	send_eggs(game, x, y);
}