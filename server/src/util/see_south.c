/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   see_south.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 12:38:42 by gmohlamo          #+#    #+#             */
/*   Updated: 2020/01/20 21:41:34 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zappy.h>

static t_list	*horizontal(t_game *game, t_client *client, int *block,
	size_t level)
{
	int			start[2];
	t_list		*lst;

	lst = NULL;
	start[0] = (block[0] + (level / 2)) % game->x;
	start[1] = block[1];
	while (level)
	{
		if (lst == NULL)
			lst = ft_lstnew(start, sizeof(start));
		else
			next_link_see(lst, start, sizeof(start));
		start[0] = start[0] - 1;
		if (start[0] < 0)
			start[0] = (game->x - 1) + start[0];
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

	ft_bzero(block, sizeof(block));
	block[0] = client->x;
	block[1] = client->y;
	lst = ft_lstnew(block, sizeof(block));
	ptr = lst;
	level = 0;
	while (level < client->level)
	{
		level++;
		block[1] = (block[1] + 1) % game->y;
		ptr->next = horizontal(game, client, block, (level * 2) + 1);
		while (ptr->next)
			ptr = ptr->next;
	}
	*coords = lst;
}

/*
** see_south()
** sends information to the client of the blocks south of its position
*/

void			see_south(t_game *game, t_client *client, t_list **blocks)
{
	t_list		*coordinates;

	coordinates = NULL;
	aquire_coords(game, client, &coordinates);
	*blocks = coordinates;
}