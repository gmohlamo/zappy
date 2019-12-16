/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_teams.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 16:48:26 by gmohlamo          #+#    #+#             */
/*   Updated: 2019/12/16 22:03:59 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zappy.h>

//initialize the teams
t_team			*new_teams(t_game *game, size_t count)
{
	size_t		itr;

	itr = 0;
	while (itr < count)
	{
		game->teams[itr].name = game->team_names[itr];
		game->teams[itr].team_size = game->allowed_clients;
		itr++;
	}
	return (game->teams);
}

//create the game's teams
t_team			*init_teams(t_game *game)
{
	size_t		count;

	count = 0;
	while (game->team_names[count])
	{
		if (!ft_isalnum(game->team_names[count]))
			break ;
		count++;
	}
	game->team_count = count;
	game->teams = ft_memalloc(sizeof(t_team) * (count + 1));
	if (!game->teams)
		return (NULL);
	return (new_teams(game, count));
}