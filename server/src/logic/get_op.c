/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 07:42:00 by gmohlamo          #+#    #+#             */
/*   Updated: 2019/12/29 08:06:02 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zappy.h>

/*
** get_op()
** add the right op command
** bear in mind that spawn is the fork command.
** apart from fork, the other commands match their enum values
*/

enum e_operations		get_op(t_client *client)
{
	if (ft_strstr((char*)client->lines->content, "advance"))
		return (advance);
	else if (ft_strstr((char*)client->lines->content, "right"))
		return (right);
	else if (ft_strstr((char*)client->lines->content, "left"))
		return (left);
	else if (ft_strstr((char*)client->lines->content, "see"))
		return (see);
	else if (ft_strstr((char*)client->lines->content, "inventory"))
		return (inventory);
	else if (ft_strstr((char*)client->lines->content, "take"))
		return (take);
	else if (ft_strstr((char*)client->lines->content, "put"))
		return (put);
	else if (ft_strstr((char*)client->lines->content, "kick"))
		return (kick);
	else if (ft_strstr((char*)client->lines->content, "broadcast"))
		return (broadcast);
	else if (ft_strstr((char*)client->lines->content, "incantation"))
		return (incantation);
	else if (ft_strstr((char*)client->lines->content, "fork"))
		return (spawn);
	else if (ft_strstr((char*)client->lines->content, "connect_nbr"))
		return (connect_nbr);
	return (none);
}