/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 17:32:08 by gmohlamo          #+#    #+#             */
/*   Updated: 2019/12/28 17:38:24 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zappy.h>

//now you don't need to write too much code to cater for an operation
//just call the function like a method in cpp
void			add_operations(t_game *game)
{
	game->operations[advance] = advance_op;
	game->operations[right] = right_op;
	game->operations[left] = left_op;
	game->operations[see] = see_op;
	game->operations[inventory] = inventory_op;
	game->operations[take] = take_op;
	game->operations[put] = put_op;
	game->operations[kick] = kick_op;
	game->operations[broadcast] = broadcast_op;
	game->operations[incantation] = incantation_op;
	game->operations[spawn] = fork_op;
	game->operations[connect_nbr] = connect_nbr_op;
	game->operations[death] = death_op;
}