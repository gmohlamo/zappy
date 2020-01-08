/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_gfx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 14:49:54 by gmohlamo          #+#    #+#             */
/*   Updated: 2020/01/03 22:59:04 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zappy.h>
#include <gfx.h>

/*
** update_gfx()
** updates the gfx client about the new position or orientation of the client
** identified by its client_nbr
*/

void			update_gfx(t_game *game, t_client *client)
{
	char		buffer[1024];

	ft_bzero(buffer, 1024);
	sprintf(buffer, "block %d %d\n", client->x, client->y);
	send(client->fd, buffer, ft_strlen(buffer), MSG_DONTWAIT);
	ft_bzero(buffer, 1024);
	sprintf(buffer, "client %zu %s %zu %zu\n", client->nbr, client->team->name,
		client->level, client->orientation);
	send(client->fd, buffer, ft_strlen(buffer), MSG_DONTWAIT);
	sprintf(buffer, "end\n");
	send(client->fd, buffer, ft_strlen(buffer), MSG_DONTWAIT);
	if (!game->gfx)
		return ;
	ft_bzero(buffer, 1024);
	sprintf(buffer, "block %d %d\n", client->x, client->y);
	send(game->gfx, buffer, ft_strlen(buffer), MSG_DONTWAIT);
	ft_bzero(buffer, 1024);
	sprintf(buffer, "client %zu %s %zu %zu\n", client->nbr, client->team->name,
		client->level, client->orientation);
	send(game->gfx, buffer, ft_strlen(buffer), MSG_DONTWAIT);
	ft_bzero(buffer, 1024);
	sprintf(buffer, "end\n");
	send(game->gfx, buffer, ft_strlen(buffer), MSG_DONTWAIT);
}