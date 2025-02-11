/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 18:18:23 by gmohlamo          #+#    #+#             */
/*   Updated: 2020/01/03 22:50:56 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zappy.h>

void				right_op(t_game *game, t_client *client)
{
	t_list			*lst;

	client->orientation = (client->orientation + 1) % 4;
	lst = client->lines;
	client->lines = lst->next;
	free(lst->content);
	free(lst);
	send(client->fd, "ok\n", 3, MSG_DONTWAIT);
	client->op = none;
	client->op_complete = true;
	update_gfx(game, client);
}