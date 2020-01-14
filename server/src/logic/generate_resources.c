/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_resources.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 10:37:45 by gmohlamo          #+#    #+#             */
/*   Updated: 2019/12/31 11:36:16 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zappy.h>

/*
** generate_resources()
** generate resources in random locations based on the map size
** 1. get the area size of the map and generate for about a quarter of that area.
*/

void			generate_resources(t_game *game)
{
	size_t		amount;
	size_t		i;
	t_objects	*objects;

	objects = ft_memalloc(sizeof(t_objects));
	amount = (game->x * game->y) / 2;
	objects->count = amount;
	objects->objects = ft_memalloc(sizeof(t_object) * amount);
	i = 0;
	while (i < amount)
	{
		objects->objects[i].x = (rand() % game->x);
		objects->objects[i].y = (rand() % game->y);
		objects->objects[i].type = (rand() % 7);
		//printf("%zu. Created resource at %d %d of type %d\n", i, objects->objects[i].x, objects->objects[i].y, objects->objects[i].type);
		//suprisingly fast
		i++;
	}
	ft_putendl("Got here");
	game->objects = objects;
	ft_putendl("got the objects");
}