/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 10:47:34 by gmohlamo          #+#    #+#             */
/*   Updated: 2020/01/18 13:38:14 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zappy.h>

/*
** This runs our program, but it is not in the same directories as
** the other source files. You can create another main function in a seperate
** file for testing purposes. 
*/

int     main(int ac, char **av)
{
	t_game *game;

	srand(time(0));
	if (ac > 1)
	{
		game = init_game(av, ac);
		run_game(game);
	}
	else
		usage_exit();
	return (0);
}