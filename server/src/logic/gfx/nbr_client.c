/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_client.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 11:10:51 by gmohlamo          #+#    #+#             */
/*   Updated: 2020/01/02 09:00:48 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zappy.h>
#include <gfx.h>

void			nbr_client(t_game *game, t_client *client)
{
	char		*str;

	str = ft_itoa(client->nbr);
	send(game->gfx, str, ft_strlen(str), MSG_DONTWAIT);
	free(str);
}