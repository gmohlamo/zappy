/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_level_req.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 09:34:34 by gmohlamo          #+#    #+#             */
/*   Updated: 2020/01/16 09:37:29 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zappy.h>

/*
** check_level_req()
** checks if the requirements to ascend to another level are met by the all other clients
*/

void			check_level_req(t_game *game, t_client *client)
{
	if (client->level <= 2)
		level_one_check(game, client);
}