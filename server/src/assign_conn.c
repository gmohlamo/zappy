/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_conn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 10:19:38 by gmohlamo          #+#    #+#             */
/*   Updated: 2019/12/26 13:03:02 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zappy.h>

//assign a connection either to the gfx client or a team member client
void		assign_conn(t_game *game, t_connection *conn)
{
	size_t	itr;

	itr = 0;
	if (!ft_strncmp(conn->line, GFX, ft_strlen(GFX)) && !game->gfx)
	{
		add_gfx(game, conn);
		return ;
	}
	while (itr < game->team_count)
	{
		ft_putstr("current team name: ");
		ft_putendl(game->teams[itr].name);
		ft_putstr("requested team name: ");
		ft_putstr(conn->line);
		if (ft_strstr(conn->line, game->teams[itr].name))
		{
			ft_putendl("found matching team");
			append_client(game, conn, &(game->teams[itr]));
			return ;
		}
		itr++;
	}
	close_connection(game, conn->fd);
}