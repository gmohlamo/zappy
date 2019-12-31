/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 17:01:39 by gmohlamo          #+#    #+#             */
/*   Updated: 2019/12/31 09:45:44 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zappy.h>

static void			process_command(t_game *game, t_client *client)
{
	//check if the client can run the current command
	if (client->cost)
		return ;
	if (client->life == 0)
		client->op = death;
	if (client->op != none)
		game->operations[client->op](game, client);
	//looks complicated but...
	//https://stackoverflow.com/questions/5309859/how-to-define-an-array-of-functions-in-c
	//shows how this should work
	//need to make sure that the functions are inserted into the game struct on initialization
	if (client->op != death)
		client->op = none; //gotta reset it and process the next line after this.
	client->op_complete = true;
}

void				run_commands(t_game *game)
{
	t_client		*clients;
	t_calc			c;
	size_t			diff;

	diff = 0;
	clients = game->clients;
	gettimeofday(&(c.tv), &(c.tz));
	while (clients)
	{
		if (FD_ISSET(clients->fd, &(game->set)))
		{
			diff = (c.tv.tv_sec - clients->tv.tv_sec) * game->timeout;
			adjust_client_life(game, clients, &c, diff); //determine if the cost of the desired operation has
			//passed of if the client has died
			process_command(game, clients);
			move_backlog(game, clients); //get the next line in the line backlog
		}
		clients = clients->next;
	}
}