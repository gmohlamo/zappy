/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   incantation_failure.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 14:17:52 by gmohlamo          #+#    #+#             */
/*   Updated: 2020/01/18 13:42:39 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zappy.h>

enum e_operations		incantation_failure(t_client *client)
{
	t_list				*lst;

	lst = client->lines;
	client->lines = lst->next;
	send(client->fd, "ko\n", 3, MSG_DONTWAIT);
	free(lst->content);
	free(lst);
	return (none);
}