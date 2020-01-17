/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   incantation_failure.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 14:17:52 by gmohlamo          #+#    #+#             */
/*   Updated: 2020/01/17 01:05:13 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zappy.h>

enum e_operations		incantation_failure(t_client *client)
{
	send(client->fd, "ko\n", 3, MSG_DONTWAIT);
	return (none);
}