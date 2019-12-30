/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   see.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 18:18:03 by gmohlamo          #+#    #+#             */
/*   Updated: 2019/12/30 15:57:05 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zappy.h>

void			see_op(t_game *game, t_client *client)
{
	char		*str = "calling the see operation";
	send(client->fd, str, ft_strlen(str), MSG_DONTWAIT);
}