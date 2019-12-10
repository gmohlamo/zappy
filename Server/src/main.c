/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 10:47:34 by gmohlamo          #+#    #+#             */
/*   Updated: 2019/12/10 10:50:44 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zappy.h>

int     main(int ac, char **av)
{
	t_game *game;

	srand(time(0)); //used to made pseudo random placement of objects when we initiate the game
	if (ac > 1)
	{
		game = init_game(av, ac);
		run_game(game);
	}
	else
		usage_exit();
	return (0);
}