/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_conn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 22:09:48 by gmohlamo          #+#    #+#             */
/*   Updated: 2019/12/16 22:13:28 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zappy.h>

t_connection		*find_conn(t_game *game, int fd)
{
	t_connection	*ptr;

	ptr = game->connections;
	while (ptr)
	{
		if (ptr->fd == fd)
			return (ptr);
		ptr = ptr->next;
	}
	return (NULL);
}

t_client			*client(t_game *game, int fd)
{
	t_client		*ptr;

	ptr = game->clients;
	while (ptr)
	{
		if (ptr->fd == fd)
			return (ptr);
		ptr = ptr->next;
	}
	return (NULL);
}