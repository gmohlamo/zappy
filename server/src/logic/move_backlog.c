/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_backlog.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 07:32:01 by gmohlamo          #+#    #+#             */
/*   Updated: 2020/01/16 10:25:00 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zappy.h>

/*
** move_backlog()
** deal with the line backlog and add new information to it.
** basically, take the current string and find the matching op code
*/

void				move_backlog(t_game *game, t_client *client)
{
	if (client->op != none)
		ft_putendl("added a new operation");
	if (client->op_complete == false)
		return ;
	if (client->lines == NULL)
		return ;
	ft_putstr(client->lines->content);
	if (!ft_strchr((char*)client->lines->content, '\n'))
		return ; //checking if we should move to the next command
	if (client->op == none) //after an operation has been completed the op_code should be returned to none
		client->op = get_op(game, client); //moved the current operation onto the client
	ft_putendl("moving backlog");
	add_op_cost(client);
}