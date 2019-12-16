/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_connection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 16:10:08 by gmohlamo          #+#    #+#             */
/*   Updated: 2019/12/16 10:25:09 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zappy.h>

//so when a new connection is accepted, we will append it to a list of connections
//this will allow us to figure out if we have a connection from a client or the gfx
void				append_connection(t_game *game, t_connection *conn)
{
	t_connection	*ptr;

	ptr = game->connections;
	printf("%d new file descriptor\n", conn->fd);
	if (conn->fd >= game->max_fd)
		game->max_fd = conn->fd + 1;
	FD_SET(conn->fd, &(game->set));
	if (ptr)
	{
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = conn;
	}
	else
		game->connections = conn;
	send(conn->fd, "WELCOME\n", 8, MSG_DONTWAIT);
}