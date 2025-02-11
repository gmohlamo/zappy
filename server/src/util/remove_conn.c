/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_conn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 21:30:34 by gmohlamo          #+#    #+#             */
/*   Updated: 2020/01/03 02:36:00 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zappy.h>

static void			clean_conn(t_connection *conn)
{
	if (conn->line)
		free(conn->line);
	free(conn);
}

//remove a client from the linked list of clients
//difference is that this one does not close the file descriptor
//and clear it in the set
void				remove_conn(t_game *game, t_connection *conn)
{
	t_connection	*ptr;
	t_connection	*temp;

	if (conn == game->connections)
		game->connections = conn->next;
	else
	{
		ptr = game->connections;
		while (ptr)
		{
			if (ptr->next == conn)
			{
				ptr->next = conn->next;
				break ;
			}
			ptr = ptr->next;
		}
	}
	clean_conn(conn);
}