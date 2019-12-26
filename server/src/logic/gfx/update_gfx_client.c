/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_gfx_client.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 13:50:24 by gmohlamo          #+#    #+#             */
/*   Updated: 2019/12/26 13:57:43 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zappy.h>
#include <gfx.h>

void			update_gfx_client(t_game *game, t_client *client)
{
	char		buffer[1024];

	ft_bzero(buffer, 1024);
	if (game->gfx)
	{
		sprintf(buffer, "block %d %d\n", client->x, client->y);
		send(game->gfx, buffer, ft_strlen(buffer), MSG_DONTWAIT);
		ft_bzero(buffer, 1024);
		sprintf(buffer, "client %zu %s %zu %zu\n", client->nbr,
			client->team->name, client->level, client->orientation);
		send(game->gfx, buffer, ft_strlen(buffer), MSG_DONTWAIT);
		ft_bzero(buffer, 1024);
		sprintf(buffer, "end\n");
		send(game->gfx, buffer, ft_strlen(buffer), MSG_DONTWAIT); //just to inform the gfx about a new player
	}
}