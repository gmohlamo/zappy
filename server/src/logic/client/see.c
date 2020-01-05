/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   see.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 18:18:03 by gmohlamo          #+#    #+#             */
/*   Updated: 2020/01/05 04:36:38 by gmohlamo         ###   ########.fr       */
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
	
	if (client->orientation == 0)
		see_north(game, client);
	else if (client->orientation == 1)
		see_east(game, client);
	else if (client->orientation == 2)
		see_south(game, client);
	else
		see_west(game, client);
	client->op = none;
	client->op_complete = true;
	lst = client->lines;
	client->lines = client->lines->next;
	free(lst->content);
	free(lst);
}