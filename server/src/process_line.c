/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 16:25:17 by gmohlamo          #+#    #+#             */
/*   Updated: 2019/12/28 17:41:25 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zappy.h>

void		close_gfx(t_game *game, char *msg)
{
	ft_putendl(msg);
	close(game->gfx);
	close_clients(game);
}

t_client			*match_line(t_game *game, int fd)
{
	t_connection	*conn;
	t_client		*client;

	client = NULL;
	conn = NULL;
	if ((client = find_client(game, fd)))
		append_line(game, client);
	else if ((conn = find_conn(game, fd)))
		process_or_close(game, conn);
	return (client);
}

t_client			*process_line(t_game *game, int fd)
{
	char			buffer[1025];
	char			*temp;

	printf("About to process line\n");
	ft_bzero(buffer, 1025);
	int		bytes_read;
	bytes_read = recv(fd, buffer, 1024, MSG_DONTWAIT);
	ft_putendl(buffer);
	if (!bytes_read)
	{
		close_connection(game, fd);
		return (NULL);
	}
	temp = ft_strsafejoin(game->gfx_line, buffer);
	if (game->gfx_line)
		free(game->gfx_line);
	game->gfx_line = temp;
	return (match_line(game, fd));
}