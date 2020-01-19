/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_team.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 12:28:17 by gmohlamo          #+#    #+#             */
/*   Updated: 2020/01/19 12:30:15 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zappy.h>

t_team				*last_team(t_game *game)
{
	t_client		*clients;

	clients = game->clients;
	while (clients)
	{
		if (clients->life)
			return (clients->team);
		clients = clients->next;
	}
	return (NULL);
}