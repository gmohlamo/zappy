/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_gfx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 22:17:15 by gmohlamo          #+#    #+#             */
/*   Updated: 2019/12/17 15:44:17 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zappy.h>

void			add_gfx(t_game *game, t_connection *conn)
{
	game->gfx = conn->fd;
	remove_conn(game, conn);
	send_init_gfx(game);
}