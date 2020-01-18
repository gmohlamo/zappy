/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_connection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 16:51:43 by gmohlamo          #+#    #+#             */
/*   Updated: 2019/12/16 22:32:52 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zappy.h>

static void			remove_connection(t_connection *target, t_game *game)
{
	t_connection	*cur_conn;

	cur_conn = game->connections;
	while (cur_conn)
	{
		if (cur_conn->next == target)
		{
			cur_conn->next = target->next;
			break ;
		}
		cur_conn = cur_conn->next;
	}
	FD_CLR(target->fd, &(game->set));
	free(target);
}

void				remove_client(t_client *target, t_game *game)
{
	t_client	*cur_client;

	cur_client = game->clients;
	while (cur_client)
	{
		if (cur_client->next == target)
		{
			cur_client->next = target->next;
			break ;
		}
		cur_client = cur_client->next;
	}
	FD_CLR(target->fd, &(game->set));
	close(target->fd);
	free(target);
}

bool				find_target_connection(t_game *game, int fd)
{
	void			*ptr;
	t_connection	*conn;

	conn = game->connections;
	while (conn)
	{
		ptr = conn;
		if (((t_connection*)ptr)->fd == fd && ptr == game->connections)
		{
			game->connections = ((t_connection*)ptr)->next;
			FD_CLR(((t_connection*)ptr)->fd, &(game->set));
			free(ptr);
			return (true);
		}
		else
			remove_connection(ptr, game);
		conn = conn->next;
	}
	return (false);
}

//close a connection to the server
void				close_connection(t_game *game, t_connection *conn)
{
	t_connection	*next;
	t_connection	*prev;

	if (conn)
	{
		next = conn->next;
		prev = game->connections;
		if (prev != conn)
		{
			while (prev->next != conn)
				prev = prev->next;
			prev->next = next;
		}
		else
			game->connections = next; //make sure the rest of this code has nothing to do with what should stay in the game
		FD_CLR(conn->fd, &(game->set)); //remove the connection file descriptor
		close(conn->fd);
		free(conn->line);
		free(conn);
	}
}