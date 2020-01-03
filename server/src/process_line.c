/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 16:25:17 by gmohlamo          #+#    #+#             */
/*   Updated: 2020/01/03 02:28:38 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zappy.h>

void		close_gfx(t_game *game)
{
	FD_CLR(game->gfx, &(game->set));
	close(game->gfx);
	game->gfx = 0;
}

t_client			*match_line(t_game *game, int fd)
{
	t_connection	*conn;
	t_client		*client;
	bool			append;

	ft_putendl("got into match_line()\n");
	client = NULL;
	conn = NULL;
	append = false;
	if ((client = find_client(game, fd)))
		append = append_line(game, client);
	else if ((conn = find_conn(game, fd)))
		process_or_close(game, conn);
	ft_strdel((char**)&(game->gfx_line));
	return (client);
}

/*
** process_line()
** reads input from the file descriptor
** adds a list struct to the connection to hold the line.
** works much like a circular buffer
** it is dynamic in size though, but that can be configured in zappy.h
*/

t_client			*process_line(t_game *game, int fd)
{
	char			buffer[1025];
	char			*temp;
	t_client		*client;

	client = NULL;
	ft_bzero(buffer, 1025);
	int		bytes_read;
	bytes_read = recv(fd, buffer, 1024, MSG_DONTWAIT);
	if (!bytes_read)
	{
		if (fd == game->gfx)
			close_gfx(game);
		else if ((client = find_client(game, fd)))
			close_client(game, client);
		else
			close_connection(game, find_conn(game, fd));
		return (NULL);
	}
	temp = ft_strsafejoin(game->gfx_line, buffer);
	printf("about to match line\n");
	if (game->gfx_line)
		free(game->gfx_line);
	game->gfx_line = temp;
	return (match_line(game, fd));
}