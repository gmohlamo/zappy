/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_advance_gfx.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 11:02:27 by gmohlamo          #+#    #+#             */
/*   Updated: 2019/12/18 11:40:22 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zappy.h>
#include <gfx.h>

void			client_advance_gfx(t_game *game, t_client *client)
{
	char		*str;
	send(game->gfx, "advance ", 5, MSG_DONTWAIT);
	nbr_client(game, client);
	str = ft_strjoinint(" ", client->x);
	send(game->gfx, str, ft_strlen(str), MSG_DONTWAIT);
	free(str);
	str = ft_strjoinint(" ", client->y);
	send(game->gfx, str, ft_strlen(str), MSG_DONTWAIT);
	free(str);
	send(game->gfx, "\n", 1, MSG_DONTWAIT);
}