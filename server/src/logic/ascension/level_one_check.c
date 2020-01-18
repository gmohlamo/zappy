/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level_one_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 08:59:35 by gmohlamo          #+#    #+#             */
/*   Updated: 2020/01/18 09:11:14 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zappy.h>

/*
** level_one_check
** confirms whether an incantation is possible for the client
*/

enum e_operations		level_one_check(t_game *game, t_client *client)
{
	size_t				itr;

	itr = 0;
	while (itr < game->objects->count)
	{
		if (game->objects->objects[itr].x == client->x &&
			game->objects->objects[itr].y == client->y &&
			game->objects->objects[itr].type == linemate)
				return (incantation);
		itr++;
	}
	return (none);
}