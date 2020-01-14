/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 18:17:13 by gmohlamo          #+#    #+#             */
/*   Updated: 2020/01/03 22:51:26 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zappy.h>

static void			append_egg(t_game *game, t_egg *next)
{
	t_egg		*eggs;

	eggs = game->eggs;
	if (eggs)
	{
		while (eggs->next)
			eggs = eggs->next;
		eggs->next = next;
	}
	else
		game->eggs = next;
}

static void			init_egg(t_game *game, t_client *client, t_egg *egg)
{
	egg->life = (LIFE * 10);
	egg->team = client->team;
	egg->team->team_size += 1;
	gettimeofday(&egg->tv, &egg->tz);
	egg->x = client->x;
	egg->y = client->y;
	append_egg(game, egg);
}

void				fork_op(t_game *game, t_client *client)
{
	t_list				*lst;
	t_egg				*egg;

	//first spawn a new egg
	egg = ft_memalloc(sizeof(t_egg));
	init_egg(game, client, egg);
	lst = client->lines;
	client->lines = lst->next;
	free(lst->content);
	free(lst);
	send(client->fd, "ok\n", 3, MSG_DONTWAIT);
	client->op = none;
	client->op_complete = true;
}