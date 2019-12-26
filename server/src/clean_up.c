/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 16:43:45 by gmohlamo          #+#    #+#             */
/*   Updated: 2019/12/20 13:30:16 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zappy.h>

void			clean_lines(t_list *lines)
{
	t_list *line;

	while (lines)
	{
		line = lines;
		lines = lines->next;
		free(line);
	}
}

void			clean_inventory(t_inv *inv)
{
	t_inv		*item;

	while (inv)
	{
		item = inv;
		inv = inv->next;
		free(item->items);
		free(item);
	}
}

void			close_clients(t_game *game)
{
	t_client	*client;
	t_client	*ptr;

	ptr = game->clients;
	while (ptr)
	{
		client = ptr;
		ptr = ptr->next;
		clean_inventory(client->inventory);
		clean_lines(client->lines);
		free(client);
	}
}