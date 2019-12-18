/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect_nbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 18:17:02 by gmohlamo          #+#    #+#             */
/*   Updated: 2019/12/18 12:53:02 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zappy.h>

//informs the client of how many connections are still possible to make
void			connect_nbr(t_game *game, t_client *client)
{
	char		*str;

	str = ft_itoa(client->team->team_size - client->team->current_count);
	send(client->fd, str, ft_strlen(str), MSG_DONTWAIT);
}