/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 16:25:17 by gmohlamo          #+#    #+#             */
/*   Updated: 2019/12/16 15:06:42 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zappy.h>

void		close_gfx(t_game *game, char *msg)
{
	ft_putendl(msg);
	close(game->gfx);
	close_clients(game);
}

void				match_line(t_game *game, int fd)
{
	t_connection	*conn;
	t_client		*client;

	if (client = find_client(game, fd))
		append_line(game, client);
	else if (conn = find_conn(game, fd))
		process_or_close(game, conn);
}

void				process_line(t_game *game, int fd)
{
	char			buffer[1025];
	char			*temp;

	printf("About to process line\n");
	ft_bzero(buffer, 1025);
	int		bytes_read;
	bytes_read = recv(fd, buffer, 1024, MSG_DONTWAIT);
	if (!bytes_read)
	{
		close_connection(game, fd);
		return ;
	}
	temp = ft_strsafejoin(game->gfx_line, buffer);
	if (game->gfx_line)
		free(game->gfx_line);
	game->gfx_line = temp;
	match_line(game, fd);
}