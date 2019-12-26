/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_eggs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 16:13:03 by gmohlamo          #+#    #+#             */
/*   Updated: 2019/12/26 12:31:53 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gfx.h>

void			send_eggs(t_game *game, int x, int y)
{
	t_egg		*eggs;
	char		*str;
	char		*temp;

	eggs = game->eggs;
	while (eggs)
	{
		if (eggs->x == x && eggs->y == y)
		{
			str = ft_strjoin("egg ", eggs->team->name);
			temp = ft_strjoin(str, "\n");
			send(game->gfx, str, ft_strlen(str), MSG_DONTWAIT);
		}
		eggs = eggs->next;
	}
}