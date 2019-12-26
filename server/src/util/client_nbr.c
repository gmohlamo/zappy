/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 13:31:57 by gmohlamo          #+#    #+#             */
/*   Updated: 2019/12/26 13:39:05 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zappy.h>

size_t				client_nbr(t_game *game)
{
	t_client		*clients;
	size_t			nbr;

	nbr = 1;
	clients = game->clients;
	while (clients)
	{
		clients = clients->next;
		nbr++;
	}
	return (nbr);
}