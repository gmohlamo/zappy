/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_incantation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 10:13:49 by gmohlamo          #+#    #+#             */
/*   Updated: 2020/01/17 01:46:36 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zappy.h>

enum e_operations			check_incantation(t_game *game, t_client *client)
{
	if (client->level == 1)
		return (level_one_check(game, client));
	else if (client->level == 2)
		return (level_two_check(game, client));
	else if (client->level == 3)
		return (level_three_check(game, client));
	else if (client->level == 4)
		return (level_four_check(game, client));
	else if (client->level == 5)
		return (level_five_check(game, client));
	else if (client->level == 6)
		return (level_six_check(game, client));
	else if (client->level == 7)
		return (level_seven_check(game, client));
	return (incantation_failure(client));
}