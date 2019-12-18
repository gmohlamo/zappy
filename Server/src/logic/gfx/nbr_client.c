/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_client.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 11:10:51 by gmohlamo          #+#    #+#             */
/*   Updated: 2019/12/18 11:15:03 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zappy.h>
#include <gfx.h>

void			nbr_client(t_game *game, t_client *client)
{
	char		*str;
	size_t		itr;
	t_client	*clients;

	itr = 0;
	clients = game->clients;
	while (clients)
	{
		if (clients == client)
			break ;
		itr++;
		clients = clients->next;
	}
	str = ft_itoa(itr);
	send(game->gfx, str, ft_strlen(str), MSG_DONTWAIT);
	free(str);
}