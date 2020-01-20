/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_resource.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 17:43:20 by gmohlamo          #+#    #+#             */
/*   Updated: 2020/01/20 17:54:49 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zappy.h>

/*
** append_resource()
** appends to the array of resources in the resource array
*/

void			append_resource(t_game *game, enum e_resource_type type)
{
	t_objects	*objects;
	t_object	object;
	size_t		itr;

	objects = ft_memalloc(sizeof(t_objects));
	objects->count = game->objects->count;
	object.x = rand() % game->x;
	object.y = rand() % game->y;
	object.type = type;
	objects->objects = ft_memalloc(sizeof(t_object) * (objects->count + 1));
	itr = 0;
	while (itr < objects->count)
	{
		ft_memcpy(&objects->objects[itr],
			&game->objects->objects[itr], sizeof(t_object));
		itr++;
	}
	ft_memcpy(&objects->objects[itr], &object, sizeof(t_object));
	free(game->objects->objects);
	free(game->objects);
	game->objects = objects;
}