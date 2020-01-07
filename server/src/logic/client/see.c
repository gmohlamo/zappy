/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   see.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 18:18:03 by gmohlamo          #+#    #+#             */
/*   Updated: 2020/01/06 14:20:15 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zappy.h>

static void		delete_seen(void *content, size_t size)
{
	if (size)
		free(content);
	else
		ft_putendl_fd("Error: No size assigned to list content", 2);
}

/*
** see_op()
** based on the clients level
** this should allow for the user
*/

void			see_op(t_game *game, t_client *client)
{
	t_list		*lst;
	t_list		*blocks;
	char		*str = "calling the see operation\n";

	blocks = NULL;	
	if (client->orientation == 0)
		see_north(game, client, &blocks);
	else if (client->orientation == 1)
		see_east(game, client, &blocks);
	else if (client->orientation == 2)
		see_south(game, client, &blocks);
	else
		see_west(game, client, &blocks);
	send_seen(game, client, blocks);
	client->op = none;
	client->op_complete = true;
	lst = client->lines;
	client->lines = client->lines->next;
	free(lst->content);
	free(lst);
}