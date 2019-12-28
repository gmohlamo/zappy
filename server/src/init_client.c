/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 10:47:29 by gmohlamo          #+#    #+#             */
/*   Updated: 2019/12/28 17:47:08 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zappy.h>

//initialize clients
void		init_client(t_client *client, t_connection *conn, t_game *game)
{

	client->fd = conn->fd;
	client->addr = conn->addr;
	client->x = rand() % game->x;
	client->y = rand() % game->y;
	client->op = none;
	client->orientation = rand() % 4; //direction client is facing
	client->life = LIFE * 10; //we'll just divide this by LIFE and know how many life units the client has remaining
	printf("new client fd --> %d\nx --> %d\ny --> %d\norientation -->%zu\nlife --> %zu\n", client->fd, client->x, client->y, client->orientation, client->life);
	printf("team name --> %s\n", client->team->name);
}