/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 13:32:51 by gmohlamo          #+#    #+#             */
/*   Updated: 2019/12/20 13:35:42 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zappy.h>

t_client			*find_client(t_game *game, int fd)
{
	t_client		*client;

	client = game->clients;
	while (client)
	{
		if (client->fd == fd)
			return (client);
		client = client->next;
	}
	return (NULL);
}