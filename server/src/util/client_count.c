/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_count.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 09:56:52 by gmohlamo          #+#    #+#             */
/*   Updated: 2020/01/16 10:01:37 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zappy.h>

static bool			same_block(t_client *first, t_client *second)
{
	if (first->x == second->x &&
		first->y == second->y &&
		first != second)
		return (true);
	return (false);
}

size_t				client_count(t_game *game, t_client *client)
{
	size_t			num;
	t_client		*clients;

	num = 0;
	clients = game->clients;
	while (clients)
	{
		if (same_block(client, clients))
			num++;
		clients = clients->next;
	}
	return (num);
}