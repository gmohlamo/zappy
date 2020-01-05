/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   see_north.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 04:37:01 by gmohlamo          #+#    #+#             */
/*   Updated: 2020/01/05 08:59:47 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zappy.h>

static t_list		*horizontal(t_game *game, t_client *client, int *block,
	size_t level)
{
	int			start;
	size_t		itr;
	size_t		width;
	t_list		*lst;

	lst = NULL;
	start = block[0];
	return (lst);
}

static void		aquire_coords(t_game *game, t_client *client, t_list **coords)
{
	t_list		*lst;
	size_t		level;
	size_t		width;
	int			block[2];
	int			temp;

	ft_bzero(block, sizeof(block));
	block[0] = client->x;
	block[1] = client->y;
	lst = ft_lstnew(block, sizeof(int) * 2);//the first block
	level = 0;
	while (level < client->level)
	{//get the coordinates of each according to the level of the client
		level++;
		block[0] = block[0] - 1 < 0? game->y - 1: block[0] - 1;//moving north
		lst->next = horizontal(game, client, block, level);
		while (lst->next)
			lst = lst->next;
	}
	*coords = lst;
}

/*
** see_north()
** sends information to the client of the blocks north of its position
*/

void			see_north(t_game *game, t_client *client)
{
	t_list		*coordinates;

	coordinates = NULL;//first thing is to aquire the coordinates
	aquire_coords(game, client, &coordinates);
}