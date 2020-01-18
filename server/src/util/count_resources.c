/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_resources.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 01:50:34 by gmohlamo          #+#    #+#             */
/*   Updated: 2020/01/17 20:29:38 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zappy.h>

size_t			count_resources(t_game *game, t_client *client,
	enum e_resource_type type)
{
	size_t		count;
	size_t		itr;
	t_objects	*objects;

	itr = 0;
	count = 0;
	objects = game->objects;
	while (itr < objects->count)
	{
		if (objects->objects[itr].type == type &&
			objects->objects[itr].x == client->x &&
			objects->objects[itr].y == client->y)
			count++;
		itr++;
	}
	return (count);
}