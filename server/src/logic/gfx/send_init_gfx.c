/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_init_gfx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 22:35:07 by gmohlamo          #+#    #+#             */
/*   Updated: 2020/01/01 14:06:41 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zappy.h>
#include <gfx.h>

static void	board_info(t_game *game)
{
	//send board information to the gfx
	char	buffer[1024];
	char	*gfx_line;
	int		x;
	int		y;

	y= 0;
	gfx_line = NULL;
	while (y < game->y)
	{
		x = 0;
		ft_bzero(buffer, 1024);
		while (x < game->x)
		{
			//send(game->gfx, buffer, ft_strlen(buffer), MSG_DONTWAIT);
			//send contents
			if ((gfx_line = block_contents(game, x, y)))
			{
				sprintf(buffer, "block %d %d\n", x, y);
				send(game->gfx, buffer, ft_strlen(buffer), MSG_DONTWAIT);
				send(game->gfx, gfx_line, ft_strlen(gfx_line), MSG_DONTWAIT);
			}
			if (gfx_line)
				ft_strdel(&gfx_line);
			x++;
		}
		y++;
	}
}

/*
** sind_init_gfx()
** should initialization information to the gfx client.
** TODO build the string up to send instead of sending chunks at
** a time.
*/

void		send_init_gfx(t_game *game)
{
	char	buffer[1024];

	//first send map size
	ft_bzero(buffer, 1024);
	sprintf(buffer, "msz %d %d\n", game->x, game->y);
	send(game->gfx, buffer, ft_strlen(buffer), MSG_DONTWAIT);
	ft_bzero(buffer, 1024);
	//send time unit(value)
	sprintf(buffer, "sgt %d\n", game->timeout);
	send(game->gfx, buffer, ft_strlen(buffer), MSG_DONTWAIT);
	ft_bzero(buffer, 1024);
	//send block information
	board_info(game);
	sprintf(buffer, "end\n");
	send(game->gfx, buffer, ft_strlen(buffer), MSG_DONTWAIT);
}