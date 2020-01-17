/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level_three_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 11:14:17 by gmohlamo          #+#    #+#             */
/*   Updated: 2020/01/17 02:02:55 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zappy.h>

/*
** level_three_check()
** checks that the requirements to upgrade 3
** needs
** 2 players
** 2 linemate
** 1 sibur
** 2 phiras
** on the block.
*/

enum e_operations			level_three_check(t_game *game, t_client *client)
{
	size_t					num_clients;
	size_t					resource_num;

	num_clients = client_count(game, client);
	if (++num_clients < 2)//client count returns the number of other clients in the same block
		return (incantation_failure(client));
	if (count_resource(game, client, linemate) < 2)
		return (incantation_failure(client));
	else if (count_resource(game, client, sibur) < 1)
		return (incantation_failure(client));
	if (count_resource(game, client, phiras) < 1)
		return (incantation_failure(client));
	return (incantation);
}