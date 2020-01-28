/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_winning_team.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 12:09:56 by gmohlamo          #+#    #+#             */
/*   Updated: 2020/01/19 23:10:37 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zappy.h>
#include <gfx.h>

/*
** team_won_level()
** The primary goal of the game is to have your clients play and get to the 
** highest level possible in the game. If a team has all of its allowed
** members in the game then we check if they got to the final level.
** This is just the first test.
*/

static void		team_won_level(t_game *game, t_team *team)
{
	t_client	*clients;

	clients = game->clients;
	if (team->current_count < team->team_size)
		return ;
	while (clients)
	{
		if (clients->team == team && clients->level != 8)
			return ;
		clients = clients->next;
	}
	gfx_winner(game, team);
	close_game(game);
}

static size_t	team_dead(t_game *game, t_team *team)
{
	t_client	*clients;
	size_t		team_size;
	size_t		count;

	count = 0;
	team_size = team->team_size;
	clients = game->clients;
	while (clients)
	{
		if (clients->life == 0 && clients->team == team)
			count++;
		else if (clients->life && clients->team == team)
			return (0);
		clients = clients->next;
	}
	return (count == team->team_size ? 1 : 0);
}

static void		last_team_win(t_game *game)
{
	t_team		*team;
	t_client	*clients;

	team = NULL;
	clients = game->clients;
	while (clients)
	{
		if (clients->life)
		{
			team = clients->team;
			break ;
		}
		clients = clients->next;
	}
	if (team)
	{
		gfx_winner(game, team);
		printf("%s team won", team->name);
	}
	close_game(game);
}

/*
** get_winning_team()
** should give us the team
** with the most high level members
** or the team with all its members
** having the highest level
*/

void			get_winning_team(t_game *game)
{
	t_team		*teams;
	size_t		itr;
	size_t		dead;

	dead = 0;
	itr = 0;
	teams = game->teams;
	while (itr < game->team_count)
	{
		//team_won_level(game, &teams[itr]);
		//printf("here\n");
		if (team_dead(game, &teams[itr]))
			dead++;
		itr++;
	}
	if (dead >= game->team_count - 1)
	 	last_team_win(game);
}