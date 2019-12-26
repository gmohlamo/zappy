/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advance.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 18:18:33 by gmohlamo          #+#    #+#             */
/*   Updated: 2019/12/18 12:57:12 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zappy.h>

void		advance_op(t_game *game, t_client *client)
{
	if (!client->cost)
	{
		if (client->orientation == 0)
			client->y = (client->y - 1) % game->y;
		else if (client->orientation == 1)
			client->x = (client->x + 1) % game->x;
		else if (client->orientation == 2)
			client->y = (client->y + 1) % game->y;
		else
			client->x = (client->x - 1) % game->x;
	}
	send(client->fd, "ok\n", 3, MSG_DONTWAIT);
	update_gfx(game, client);
}