/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   see.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 18:18:03 by gmohlamo          #+#    #+#             */
/*   Updated: 2020/01/03 01:53:58 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zappy.h>

/*
** see_op()
** based on the clients level
** this should allow for the user
*/

void			see_op(t_game *game, t_client *client)
{
	t_list		*lst;
	char		*str = "calling the see operation\n";
	
	send(client->fd, str, ft_strlen(str), MSG_DONTWAIT);
	client->op = none;
	client->op_complete = true;
	lst = client->lines;
	client->lines = client->lines->next;
	free(lst->content);
	free(lst);
}