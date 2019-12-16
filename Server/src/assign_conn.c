/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_conn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 10:19:38 by gmohlamo          #+#    #+#             */
/*   Updated: 2019/12/16 22:04:33 by gmohlamo         ###   ########.fr       */
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
		if (ft_strstr(conn->line, game->teams[itr].name))
		{
			append_client(game, conn, game->team_names[itr]);
			break ;
		}
		itr++;
	}
}