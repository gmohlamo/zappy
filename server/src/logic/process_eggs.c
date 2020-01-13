/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_eggs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 04:20:03 by gmohlamo          #+#    #+#             */
/*   Updated: 2020/01/11 05:05:41 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zappy.h>

static void			adjust_egg_life(t_game *game, t_egg *egg, t_calc *calc, size_t diff)
{
	egg->life = diff > egg->life ? 0 : egg->life - diff;
	egg->tv = calc->tv;
}

static t_egg		*dead_egg(t_game *game, t_egg *egg)
{
	t_egg			*eggs;

	eggs = game->eggs;
	if (egg->life == 0)
	{//kill the egg
		egg->team->team_size -= 1;
		if (egg == eggs)
		{
			eggs = eggs->next;
			game->eggs = eggs;
			free(egg);
			return (eggs);
		}
		else
		{
			while (eggs->next != egg)
				eggs = eggs->next;
			eggs->next = egg->next;
			free(egg);
			return (eggs->next);
		}
	}
	else
		return (egg->next);
}

void				process_eggs(t_game *game)
{
	size_t			diff;
	t_calc			c;
	t_egg			*eggs;

	diff = 0;
	eggs = game->eggs;
	ft_bzero(&c, sizeof(t_calc));
	if (eggs)
	{
		gettimeofday(&(c.tv), &(c.tz));
		while (eggs)
		{
			diff = (c.tv.tv_sec - eggs->tv.tv_sec) * game->timeout;
			adjust_egg_life(game, eggs, &c, diff);
			eggs = dead_egg(game, eggs);//returns the next egg or NULL
		}
	}
}