/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheack_team.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 16:35:07 by gmohlamo          #+#    #+#             */
/*   Updated: 2019/12/16 20:49:01 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zappy.h>

t_team			*check_team(t_game *game, char *team_name)
{
	t_team		*teams;
	
	teams = game->teams;
	while (teams)
	{
		if (teams->name == team_name && teams->current_count < teams->team_size)
			return (teams);
		else if (teams->name == team_name)
			return (NULL);
	}
	return (NULL);
}