/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level_two_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 09:49:11 by gmohlamo          #+#    #+#             */
/*   Updated: 2020/01/17 20:35:14 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zappy.h>

/*
** level_two_check()
** checks that the requirements to upgrade between 3 and 4
** resources needed are linemate, deraumere and sibur
** additionally, there should be a minimum of 2 clients
** on the block.
*/

enum e_operations		level_two_check(t_game *game, t_client *client)
{
	t_objects			*objects;
	size_t				num_clients;
	size_t				i;
	size_t				checks[3];

	i = 0;
	ft_bzero(checks, 3 * sizeof(size_t));
	num_clients = client_count(game, client);
	objects = game->objects;
	while (i < objects->count)
	{
		if (objects->objects[i].type == linemate)
			checks[0] += 1;
		else if (objects->objects[i].type == deraumere)
			checks[1] += 1;
		else if (objects->objects[i].type == sibur)
			checks[2] += 1;
		i++;
	}
	i = 0;
	while (i< 3)
		if (checks[i++] == 0)
			return (incantation_failure(client));
	return (incantation);
}