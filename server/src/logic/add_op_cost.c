/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_op_cost.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 08:54:35 by gmohlamo          #+#    #+#             */
/*   Updated: 2019/12/30 14:47:06 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zappy.h>

void				add_op_cost(t_client *client)
{
	if (client->op == advance || client->op == right || client->op == left ||
		client->op == see || client->op == take || client->op == put ||
		client->op == broadcast)
			client->cost = 7;
	else if (client->op == inventory)
		client->cost = 1;
	else if (client->op == incantation)
	{
		send(client->fd, ELEVATE, ft_strlen(ELEVATE), MSG_DONTWAIT);
		client->cost = 300; //whether it will work or not we will process
	}
	else if (client->op == spawn)
		client->cost = 42;
	else
		client->cost = 0;
}