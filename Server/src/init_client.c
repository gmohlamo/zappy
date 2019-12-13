/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 10:47:29 by gmohlamo          #+#    #+#             */
/*   Updated: 2019/12/13 15:29:26 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zappy.h>

void		init_client(t_client *client, t_game *game)
{
	(void)game;
	client->x = rand() % 16;
	client->y = rand() % 16; //assign "random" coordinates on the games map
	client->orientation = rand() % 4; //direction client is facing
	client->life = LIFE * 10; //we'll just divide this by LIFE and know how many life units the client has remaining
}