/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   see.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 18:18:03 by gmohlamo          #+#    #+#             */
/*   Updated: 2019/12/31 10:02:32 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zappy.h>

void			see_op(t_game *game, t_client *client)
{
	char		*str = "calling the see operation\n";
	send(client->fd, str, ft_strlen(str), MSG_DONTWAIT);
	client->op = none;
	client->op_complete = true;
}