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
	char		*temp;

	temp = NULL;
	lines = client->lines;
	if (!lines)
	{
		client->lines = ft_memalloc(sizeof(t_list));
		client->lines->content = ft_strdup(game->gfx_line);
		ft_strdel(&(game->gfx_line));
	}
	return (true);
}

/*
** find_line()
** finds the latest line to add too
*/

static t_list	*find_line(t_client *client, size_t *count)
{
	t_list		*lines;

	lines = client->lines;
	while (lines && *count < CMD_BACKLOG)
	{
		*count = *count + 1;
		if (!ft_strchr(lines->content, '\n'))
			return (lines);
		lines = lines->next;
	}
	return (NULL);
}

static bool		concat_line(t_game *game, t_client *client, size_t count)
{
	t_list		*lines;

	lines = client->lines;
	if (count + 1 >= CMD_BACKLOG)
	{
		ft_strdel(&(game->gfx_line));
		return (false);
	}
	while (lines->next)
		lines = lines->next;
	lines->next = ft_memalloc(sizeof(t_list));
	lines->next->content = game->gfx_line;
	game->gfx_line = NULL;
	return (true);
}

/*
** append_line()
** should append to the last line in the backlog of allowed lines --> 10
** TODO fix this POS stat
*/

bool			append_line(t_game *game, t_client *client)
{
	t_list		*lines;
	size_t		count;
	char		*str;

	count = 0;	
	lines = client->lines;
	if (!lines)//this is the first line being added to the list
		return (add_new_line(client, game));
	else
	{
		lines = find_line(client, &count);
		if (lines)
		{
			str = ft_strjoin(lines->content, game->gfx_line);
			ft_memdel(&(lines->content));
			ft_strdel(&(game->gfx_line));
			lines->content = str;
		}
		else
			return (concat_line(game, client, count));
	}
	return (true);
}