/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_seen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 11:31:37 by gmohlamo          #+#    #+#             */
/*   Updated: 2020/01/06 15:04:37 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zappy.h>

/*
** add_seen()
** add to the string and maintain json format
*/

static void		add_seen(t_game *game, char **str, char *add, size_t num)
{
	char		*seen;
	char		*temp;

	temp = NULL;
	seen = ft_strjoin(*str, ", content-square-");
	temp = ft_strjoinint(seen, num);
	ft_strdel(str);
	ft_strdel(&seen);
	seen = ft_strjoin(temp, add);
	ft_strdel(&add);
	ft_strdel(&temp);
	*str = seen;
}

static char		*init_str(t_game *game, t_client *client, t_list *coords, size_t num)
{
	char		*str;
	char		*ptr;
	char		buffer[1024];

	str = NULL;
	ft_bzero(buffer, 1024);
	ptr = see_block(game, client, ((int*)coords->content)[0],
		((int*)coords->content)[1]);
	sprintf(buffer, "{content-square-%zu: ", num);
	str = ft_strjoin(buffer, ptr? ptr: "[]");
	ft_strdel(&ptr);
	return (str);
}

/*
** send_seen()
** sends what was seen to the client in a json formatted string
*/

void			send_seen(t_game *game, t_client *client, t_list *coords)
{
	char		*str;
	char		*ptr;
	size_t		num;
	t_list		*temp;

	str = NULL;
	num = 0;
	while (coords)
	{
		if (!str)
			str = init_str(game, client, coords, num);
		else
			add_seen(game, &str, see_block(game, client,
				((int*)(coords->content))[0], ((int*)(coords->content))[1]), num);
		temp = coords;
		coords = coords->next;
		free(temp->content);
		free(temp);
		num++;
	}
	ptr = ft_strjoin(str, "}\n");
	send(game->gfx, ptr, ft_strlen(ptr), MSG_DONTWAIT);
	ft_strdel(&ptr);
	ft_strdel(&str);
	//this should send block contents to the client.
}