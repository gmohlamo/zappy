/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_client.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 09:19:15 by gmohlamo          #+#    #+#             */
/*   Updated: 2020/01/18 09:22:17 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zappy.h>

void			close_client(t_game *game, t_client *client)
{
	FD_CLR(client->fd, &(game->set));
	close(client->fd);
	client->fd = -1;
	client->op_complete = true;
	client->op = death;
}