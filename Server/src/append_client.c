/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_client.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 10:47:23 by gmohlamo          #+#    #+#             */
/*   Updated: 2019/12/17 17:44:15 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zappy.h>

//create a new client to play the game
static t_client	*new_client(t_game *game, t_connection *conn, char *team_name)
{
	t_client	*client;
	t_team		*team;
	char	buffer[1024];

	if ((team = check_team(game, team_name)) == NULL)
		return (NULL);
	ft_bzero(buffer, 1024);
	client = ft_memalloc(sizeof(t_client));
	if (client)
	{
		init_client(client, game);
		client->team = team;
		client->addr = conn->addr;
		team->current_count++;
		sprintf(buffer, "%d\n", team->team_size - team->current_count);
		ft_bzero(buffer, 1024);
		sprintf(buffer, "%d %d\n", client->x, client->y);
		send(client->fd, buffer, ft_strlen(buffer), MSG_DONTWAIT);
	}
	else
		return (client);
}

//append a new client to the server
void			append_client(t_game *game, t_connection *conn, char *team_name)
{
	t_client	*ptr;
	t_client	*client;

	ptr = game->clients;
	client = new_client(game, conn, team_name);
	if (client)
	{
		if (ptr)
		{
			while (ptr->next)
				ptr = ptr->next;
			ptr->next = client;
		}
		else
			game->clients = client;
		init_client(client, game);
		remove_conn(game, conn);
	}
}