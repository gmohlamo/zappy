/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   see_north.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 04:37:01 by gmohlamo          #+#    #+#             */
/*   Updated: 2020/01/20 21:41:15 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zappy.h>

/*
** horizontal()
** This will get the coordinates of the blocks horizontally
*/

static t_list		*horizontal(t_game *game, t_client *client, int *block,
	size_t level)
{
	int			start[2];
	t_list		*lst;

	lst = NULL;
	start[0] = block[0] - (level / 2);
	if (start[0] < 0)
		start[0] = game->x + start[0];
	start[1] = block[1];
	while (level)
	{
		if (lst == NULL)
			lst = ft_lstnew(start, sizeof(start));
		else
			next_link_see(lst, start, sizeof(start));
		start[0] = (start[0] + 1) % game->x; //helps it wrap around the board
		level--;
	}
	return (lst);
}

static void		aquire_coords(t_game *game, t_client *client, t_list **coords)
{
	t_list		*lst;
	t_list		*ptr;
	size_t		level;
	int			block[2];
	int			temp;

	block[0] = client->x;
	block[1] = client->y;
	lst = ft_lstnew(block, sizeof(block));//the first block
	ptr = lst;
	level = 0;
	while (level < client->level)
	{//get the coordinates of each according to the level of the client
		level++;
		block[1] = block[1] - 1 < 0? game->y - 1: block[1] - 1;//moving north
		ptr->next = horizontal(game, client, block, (level * 2) + 1);
		while (ptr->next)
			ptr = ptr->next;
	}
	*coords = lst;
}

/*
** see_north()
** sends information to the client of the blocks north of its position
*/

void			see_north(t_game *game, t_client *client, t_list **blocks)
{
	t_list		*coordinates;

	coordinates = NULL;//first thing is to aquire the coordinates
	aquire_coords(game, client, &coordinates);
	*blocks = coordinates;
}