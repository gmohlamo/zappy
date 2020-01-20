/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   consume_food.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 17:38:39 by gmohlamo          #+#    #+#             */
/*   Updated: 2020/01/20 17:40:46 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zappy.h>

void			consume_food(t_game *game, t_client *client)
{
	client->life += LIFE;
	client->inventory->food_count--;
	append_resource(game, food);
}