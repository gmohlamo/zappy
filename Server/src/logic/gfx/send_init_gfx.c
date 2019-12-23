/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_init_gfx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 22:35:07 by gmohlamo          #+#    #+#             */
/*   Updated: 2019/12/23 10:58:54 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zappy.h>
#include <gfx.h>

void		board_info(t_game *game)
{
	//send board information to the gfx
	char	buffer[1024];
	int		x;
	int		y;

	y= 0;
	while (y < game->y)
	{
		x = 0;
		ft_bzero(buffer, 1024);
		while (x < game->x)
		{
			ft_putendl("running through the board");
			//protocol for this will be that we send the block coordinates first
			//then the contents, starting with clients and then resources
			sprintf(buffer, "block %d %d\n", x, y); //the current block
			send(game->gfx, buffer, ft_strlen(buffer), MSG_DONTWAIT);
			//send contents
			block_contents(game, x, y); //send the contents of this block
			x++;
		}
		y++;
	}
}

void		send_init_gfx(t_game *game)
{
	ft_putendl("initializing graphics client");
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
}