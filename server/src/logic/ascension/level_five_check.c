/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level_five_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 02:10:15 by gmohlamo          #+#    #+#             */
/*   Updated: 2020/01/17 02:14:53 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zappy.h>

enum e_operations		level_five_check(t_game *game, t_client *client)
{
	size_t				num;

	num = client_count(game, client);
	if (++num < 4)
		return (incantation_failure(client));
	else if (count_resources(game, client, linemate) < 1)
		return (incantation_failure(client));
	else if (count_resources(game, client, deraumere) < 1)
		return (incantation_failure(client));
	else if (count_resources(game, client, sibur) < 2)
		return (incantation_failure(client));
	else if (count_resources(game, client, phiras) < 1)
		return (incantation_failure(client));
	return (incantation);
}