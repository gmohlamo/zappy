/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_client.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 10:47:23 by gmohlamo          #+#    #+#             */
/*   Updated: 2020/01/14 01:21:21 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zappy.h>

//create a new client to play the game
static t_client	*new_client(t_game *game, t_connection *conn, t_team *team)
{
	t_client	*client;
	char	buffer[1024];

	ft_bzero(buffer, 1024);
	client = NULL;
	client = ft_memalloc(sizeof(t_client));
	client->nbr = client_nbr(game);
	client->team = team;
	init_client(client, conn, game);
	team->current_count++;
	sprintf(buffer, "%lu\n", client->nbr);
	send(client->fd, buffer, ft_strlen(buffer), MSG_DONTWAIT);
	ft_bzero(buffer, 1024);
	sprintf(buffer, "%d %d\n", client->x, client->y);
	send(client->fd, buffer, ft_strlen(buffer), MSG_DONTWAIT);
	update_gfx_client(game, client);
	gettimeofday(&(client->tv), &(client->tz)); //start draining life
	remove_conn(game, conn);
	return (client);
}

//append a new client to the server
void			append_client(t_game *game, t_connection *conn, t_team *team)
{
	t_client	*ptr;
	t_client	*client;

	ptr = game->clients;
	client = new_client(game, conn, team);
	if (!client)
		return close_connection(game, conn);
	if (ptr) //should there already be clients connected
	{
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = client;
	}
	else
		game->clients = client;
}