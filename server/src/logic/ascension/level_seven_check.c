/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level_seven_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 02:19:29 by gmohlamo          #+#    #+#             */
/*   Updated: 2020/01/17 02:23:38 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zappy.h>

enum e_operations			levl_seven_check(t_game *game, t_client *client)
{
	size_t					num;

	num = client_count(game, client);
	if (++num < 6)
		return (incantation_failure(client));
	else if (count_resources(game, client, linemate) < 2)
		return (incantation_failure(client));
	else if (count_resources(game, client, deraumere) < 2)
		return (incantation_failure(client));
	else if (count_resources(game, client, sibur) < 2)
		return (incantation_failure(client));
	else if (count_resources(game, client, mendiane) < 2)
		return (incantation_failure(client));
	else if (count_resources(game, client, phiras) < 2)
		return (incantation_failure(client));
	else if (count_resources(game, client, thystame) < 1)
		return (incantation_failure(client));
	return (incantation);
}