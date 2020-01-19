/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_op_cost.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 08:54:35 by gmohlamo          #+#    #+#             */
/*   Updated: 2020/01/18 13:41:56 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zappy.h>

void				add_op_cost(t_client *client)
{
	client->op_complete = false;
	if (client->op == advance || client->op == right || client->op == left ||
		client->op == see || client->op == take || client->op == put ||
		client->op == broadcast)
			client->cost = 7;
	else if (client->op == inventory)
		client->cost = 1;
	else if (client->op == incantation)
		client->cost = 300; //whether it will work or not we will process
	else if (client->op == spawn)
		client->cost = 42;
	else
		client->cost = 0;
	if (client->op != none)
		client->op_complete = false;
}