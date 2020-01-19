/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx_winner.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 23:01:22 by gmohlamo          #+#    #+#             */
/*   Updated: 2020/01/19 23:04:25 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gfx.h>

void			gfx_winner(t_game *game, t_team *team)
{
	char		buffer[1024];

	ft_bzero(buffer, sizeof(buffer));
	sprintf(buffer, "winner %s\n", team->name);
	if (game->gfx > 0)
		send(game->gfx, buffer, ft_strlen(buffer), MSG_DONTWAIT);
	write(1, buffer, ft_strlen(buffer));
}