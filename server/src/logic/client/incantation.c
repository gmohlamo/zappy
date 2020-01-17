/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   incantation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 18:16:39 by gmohlamo          #+#    #+#             */
/*   Updated: 2020/01/16 10:24:23 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zappy.h>

void		incantation_op(t_game *game, t_client *client)
{
	t_list				*lst;

	lst = client->lines;
	client->lines = lst->next;
	if (client->level < 2)
		level_up_client(game, client, 2);
	else if (client->level < 3)
		level_up_client(game, client, 3);
	else if (client->level < 4)
		level_up_client(game, client, 4);
	else if (client->level < 5)
		level_up_client(game, client, 5);
	else if (client->level < 6)
		level_up_client(game, client, 6);
	else if (client->level < 7)
		level_up_client(game, client, 7);
	else if (client->level < 8)
		level_up_client(game, client, 8);
	free(lst->content);
	free(lst);
	send(client->fd, "ok\n", 3, MSG_DONTWAIT);
	client->op = none;
	client->op_complete = true;
}