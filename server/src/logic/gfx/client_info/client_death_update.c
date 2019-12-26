/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_death_update.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 13:02:48 by gmohlamo          #+#    #+#             */
/*   Updated: 2019/12/18 13:06:49 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zappy.h>
#include <gfx.h>

void			client_death_update(t_game *game, t_client *client)
{
	send(game->gfx, "death ", 6, MSG_DONTWAIT);
	nbr_client(game, client);
	send(game->gfx, "\n", 1, MSG_DONTWAIT);
}