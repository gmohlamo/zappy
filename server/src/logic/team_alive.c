/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   team_alive.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 12:18:18 by gmohlamo          #+#    #+#             */
/*   Updated: 2020/01/19 12:20:52 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zappy.h>

size_t				team_alive(t_game *game, t_team *team)
{
	t_client		*clients;

	clients = game->clients;
	while (clients)
	{
		if (clients->team == team && clients->life > 0)
			return (1);
		clients = clients->next;
	}
	return (0);
}