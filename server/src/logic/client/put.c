/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 18:17:36 by gmohlamo          #+#    #+#             */
/*   Updated: 2020/01/03 22:53:20 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zappy.h>

static char				*reassign_resource(t_game *game, t_client *client, enum e_resource_type type)
{
	t_objects			*objects;

	objects = ft_memalloc(sizeof(t_objects));
	objects->count = game->objects->count + 1;
	objects->objects = ft_memalloc(sizeof(t_object) * objects->count);
	ft_memcpy(objects->objects, game->objects->objects, sizeof(t_object) * game->objects->count);
	objects->objects[game->objects->count].type = type;
	objects->objects[game->objects->count].x = client->x;
	objects->objects[game->objects->count].y = client->y;
	free(game->objects->objects);
	free(game->objects);
	game->objects = objects;
	return (ft_strdup("ok\n"));
}

static char				*put_down(t_game *game, t_client *client,
	enum e_resource_type type)
{
	size_t				*item;

	item = 0;
	if (type == food)
		item = &client->inventory->food_count;
	else if (type == thystame)
		item = &client->inventory->thystame_count;
	else if (type == mendiane)
		item = &client->inventory->mendiane_count;
	else if (type == sibur)
		item = &client->inventory->sibur_count;
	else if (type == deraumere)
		item = &client->inventory->deraumere_count;
	else if (type == phiras)
		item = &client->inventory->phiras_count;
	else if (type == linemate)
		item = &client->inventory->linemate_count;
	if (*item == 0)
		return (ft_strdup("ko\n"));
	else
	{
		*item = *item - 1;
		return (reassign_resource(game, client, type));
	}
}

static char				*put_item(t_game *game, t_client *client, char *item)
{
	//first identify the item
	if (ft_strstr(item, "food"))
		return (put_down(game, client, food));
	else if (ft_strstr(item, "linemate"))
		return (put_down(game, client, linemate));
	else if (ft_strstr(item, "deraumere"))
		return (put_down(game, client, deraumere));
	else if (ft_strstr(item, "sibur"))
		return (put_down(game, client, sibur));
	else if (ft_strstr(item, "mendiane"))
		return (put_down(game, client, mendiane));
	else if (ft_strstr(item, "phiras"))
		return (put_down(game, client, phiras));
	else if (ft_strstr(item, "thystame"))
		return (put_down(game, client, thystame));
	return (ft_strdup("ko\n"));
}

void					put_op(t_game *game, t_client *client)
{
	char				*item;
	char				*res;
	t_list				*lst;
	t_objects			*objects;//we are gonna append to the objects in the game map

	lst = client->lines;
	if (!(item = ft_strchr((char*)lst->content, ' ')))
		res = ft_strdup("ko\n");
	else
		res = put_item(game, client, &item[1]);
	client->lines = lst->next;
	free(lst->content);
	free(lst);
	send(client->fd, res, ft_strlen(res), MSG_DONTWAIT);
	free(res);
	client->op = none;
	client->op_complete = true;
}