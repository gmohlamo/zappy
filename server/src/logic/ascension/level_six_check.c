/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level_six_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 02:15:13 by gmohlamo          #+#    #+#             */
/*   Updated: 2020/01/17 02:19:04 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zappy.h>

enum e_operations		level_six_check(t_game *game, t_client *client)
{
	size_t				num;

	num = client_count(game, client);
	if (++num < 6)
		return (incantation_failure(client));
	else if (count_resources(game, client, linemate) < 1)
		return (incantation_failure(client));
	else if (count_resources(game, client, deraumere) < 2)
		return (incantation_failure(client));
	else if (count_resources(game, client, sibur) < 3)
		return (incantation_failure(client));
	else if (count_resources(game, client, phiras) < 1)
		return (incantation_failure(client));
	return (incantation);
}