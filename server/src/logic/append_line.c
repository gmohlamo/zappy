/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 17:50:44 by gmohlamo          #+#    #+#             */
/*   Updated: 2019/12/20 14:19:52 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zappy.h>

void			append_line(t_game *game, t_client *client)
{
	t_list		*lines;
	size_t		count;
	char		*str;

	count = 0;
	lines = client->lines;
	str = NULL;
	while (lines && count < CMD_BACKLOG)
	{
		if (!ft_strchr((char*)(lines->content), '\n'))
		{
			str = ft_strjoin(lines->content, game->gfx_line);
			free(lines->content);
			lines->content = str;
			return ;
		}
		count++;
		lines = lines->next;
	}
}