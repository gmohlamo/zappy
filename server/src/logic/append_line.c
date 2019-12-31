/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 17:50:44 by gmohlamo          #+#    #+#             */
/*   Updated: 2019/12/31 09:56:47 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zappy.h>

/*
** add_new_line()
** add a new line when a line has not been found
*/
static bool		add_new_line(t_client *client, t_game *game)
{
	t_list		*lines;

	lines = NULL;
	ft_putendl("adding a new line");
	if (!client->lines)
	{
		ft_putendl("Got into the first condition");
		ft_putendl(game->gfx_line);
		client->lines = ft_memalloc(sizeof(t_list));
		client->lines->content = ft_strdup(game->gfx_line);
		ft_strdel(&game->gfx_line);
		return (true);
	}
	else
		lines = client->lines;
	while (lines->next)
		lines = lines->next;
	lines->next = ft_memalloc(sizeof(t_list));
	lines->next->content = game->gfx_line;
	ft_strdel(&game->gfx_line);
	return (true);
}

/*
** find_line()
** finds the latest line to add too
*/

t_list			*find_line(t_client *client, size_t *count)
{
	t_list		*lines;

	lines = client->lines;
	while ((lines && *count <= CMD_BACKLOG))
	{
		if (!ft_strchr((char*)(lines->content), '\n'))
			break ;
		(*count)++;
		lines = lines->next;
	}
	return (lines);
}

/*
** append_line()
** should append to the last line in the backlog of allowed lines --> 10
*/

bool			append_line(t_game *game, t_client *client)
{
	t_list		*lines;
	size_t		count;
	char		*str;

	count = 0;
	lines = client->lines;
	str = NULL;
	ft_putendl("appending to the line");
	lines = find_line(client, &count);
	ft_putendl(lines? lines->content: "did not get line");
	if (!lines && count < CMD_BACKLOG)
		return (add_new_line(client, game));
	else if (count >= CMD_BACKLOG)
		return (false);
	if (ft_strchr((char*)(lines->content), '\n'))
		return (false);
	str = ft_strjoin(lines->content, game->gfx_line);
	ft_strdel((char**)&game->gfx_line);
	free(lines->content);
	lines->content = str;
	ft_putendl("appended to the line");
	return (true);
}