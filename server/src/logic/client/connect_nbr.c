/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect_nbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 18:17:02 by gmohlamo          #+#    #+#             */
/*   Updated: 2020/01/03 22:52:34 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zappy.h>

//informs the client of how many connections are still possible to make
void			connect_nbr_op(t_game *game, t_client *client)
{
	char		*str;
	t_list				*lst;

	str = ft_itoa(client->team->team_size - client->team->current_count);
	send(client->fd, str, ft_strlen(str), MSG_DONTWAIT);
	send(client->fd, "\n", 1, MSG_DONTWAIT);
	lst = client->lines;
	client->lines = lst->next;
	free(lst->content);
	free(lst);
	send(client->fd, "ok\n", 3, MSG_DONTWAIT);
	client->op = none;
	client->op_complete = true;
}