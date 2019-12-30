/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_backlog.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 07:32:01 by gmohlamo          #+#    #+#             */
/*   Updated: 2019/12/30 15:07:06 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zappy.h>

/*
** move_backlog()
** deal with the line backlog and add new information to it.
*/

void				move_backlog(t_game *game, t_client *client)
{
	t_list			*line;

	if (client->lines == NULL)
		return ;
	line = client->lines->next; //cause we're gonna delete the current line
	ft_memdel(&(client->lines->content));
	ft_memdel((void**)&(client->lines));
	client->lines = line;
	if (!client->lines)
		return ;
	else if (!ft_strchr((char*)client->lines->content, '\n'))
		return ; //checking if we should move to the next command
	if (client->op == none)
		client->op = get_op(client); //moved the current operation onto the client
	add_op_cost(client);
}