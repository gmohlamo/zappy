/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   see_east.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 13:51:51 by gmohlamo          #+#    #+#             */
/*   Updated: 2020/01/06 14:28:39 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zappy.h>

/*
** vertical()
** This will get the coordinates of the blocks vertically
*/

static t_list	*vertical(t_game *game, t_client *client, int *block, size_t level)
{
	int			start[2];
	t_list		*lst;

	lst = NULL;
	start[0] = block[0];
	start[1] = (block[1] - (level / 2));
	if (start[1] < 0)
		start[1] = game->y + start[1];
	while (level)
	{
		if (lst == NULL)
			lst = ft_lstnew(start, sizeof(start));
		else
			next_link_see(lst, start, sizeof(start));
		start[1] = (start[1] + 1) % game->y;
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
		block[0] = (block[0] + 1) % game->x;
		ptr->next = vertical(game, client, block, (level * 2) + 1);
		while (ptr->next)
			ptr = ptr->next;
	}
	*coords = lst;
}

/*
** see_east()
** sends information to the client of the blocks east of its position
*/

void				see_east(t_game *game, t_client *client, t_list **blocks)
{
	t_list			*coordinates;

	coordinates = NULL;
	aquire_coords(game, client, &coordinates);
	*blocks = coordinates;
}