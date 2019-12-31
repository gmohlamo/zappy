/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 18:16:53 by gmohlamo          #+#    #+#             */
/*   Updated: 2019/12/31 10:01:06 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zappy.h>

void				death_op(t_game *game, t_client *client)
{
	client->op = death;
	send(client->fd, "death\n", 6, MSG_DONTWAIT);
	//the client is now 'dead' so we can close the connection
	FD_CLR(client->fd, &(game->set));
	close(client->fd);
	client->op_complete = true;
	//send update information to gfx
	client_death_update(game, client);
}