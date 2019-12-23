/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_or_close.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 19:43:50 by gmohlamo          #+#    #+#             */
/*   Updated: 2019/12/23 10:42:26 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zappy.h>

void			process_or_close(t_game *game, t_connection *conn)
{
	char		*temp;

	temp = NULL;
	if (conn->line)
	{
		temp = ft_strsafejoin(conn->line, game->gfx_line);
		ft_strdel(&(conn->line));
	}
	else
		conn->line = game->gfx_line;
	game->gfx_line = NULL;
	if (ft_strchr(conn->line, '\n'))//at this point we are ready to process this
	//line or close this connection
		assign_conn(game, conn);
}