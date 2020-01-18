/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 10:47:29 by gmohlamo          #+#    #+#             */
/*   Updated: 2020/01/05 04:52:21 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zappy.h>

//initialize clients
void		init_client(t_client *client, t_connection *conn, t_game *game)
{

	client->fd = conn->fd;
	client->addr = conn->addr;
	client->inventory = ft_memalloc(sizeof(t_inv));
	if (!team_eggs(game, client))
	{
		client->x = rand() % game->x;
		client->y = rand() % game->y;
		client->life = LIFE * 10; //we'll just divide this by LIFE and know how many life units the client has remaining
	}
	client->op = none;
	client->level = 1;
	client->op_complete = true;
	client->orientation = rand() % 4; //direction client is facing
}