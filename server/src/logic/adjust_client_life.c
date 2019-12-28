/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjust_client_life.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 17:10:16 by gmohlamo          #+#    #+#             */
/*   Updated: 2019/12/28 17:17:46 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zappy.h>

void			adjust_client_life(t_game *game, t_client *client, t_calc *calc,
	size_t diff)
{
	//check if the client has a cost which should be reduced
	client->cost = diff > client->cost ? 0 : client->cost - diff;
	//adjust life
	client->life = diff > client->life ? 0 : client->life - diff;
	client->tv = calc->tv; //change the client time to the current time
	//by now we have adjusted the client life and can safely process the command requested
	//should the cost of the command be met.
}