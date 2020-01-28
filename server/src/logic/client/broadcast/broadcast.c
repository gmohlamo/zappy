/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   broadcast.c                                        :+:      :+:    :+:   */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 18:17:20 by gmohlamo          #+#    #+#             */
/*   Updated: 2020/01/03 22:49:09 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zappy.h>

void				send_msg(int square_nb, char *message, t_client *dest)
{
	char			*part1;
	char			*part2;
	char			*part3;
	char			*part4;
	char			*msg;

	part1 = strdup("message <");
	part2 = ft_strjoin(ft_itoa(square_nb), ">,<");
	part3 = strdup(">\n");
	part4 = ft_strjoin(part1, part2);
	free(part1);
	part1 = NULL;
	part1 = ft_strjoin(part4, ft_strtrim(message) + 10);
	msg = ft_strjoin(part1, part3);
	free(part1);
	free(part2);
	free(part3);
	free(part4);
	send(dest->fd, msg, strlen(msg), MSG_DONTWAIT);
	free(msg);
}

int					choose_algo(t_game *game, t_client *src, t_client *dest)
{
	if (src->x == dest->x)
		return (vertical_calc(game, src, dest));
	else if (src->y == dest->y)
		return (horizontal_calc(game, src, dest));
	else
		return (diagonal_calc(game, src, dest));
}

void					broadcast_op(t_game *game, t_client *client)
{
	t_list				*lst;
	t_client			*clients;
	int					square_nb;

	lst = client->lines;
	client->lines = lst->next;
	clients = game->clients;
	while (clients)
	{
		if (clients != client)
		{
			square_nb = choose_algo(game, client, clients);
			send_msg(square_nb, lst->content, clients);
		}
		clients = clients->next;
	}
	free(lst->content);
	free(lst);
	send(client->fd, "ok\n", 3, MSG_DONTWAIT);
	client->op = none;
	client->op_complete = true;
}