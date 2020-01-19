/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 16:14:18 by gmohlamo          #+#    #+#             */
/*   Updated: 2020/01/19 23:00:47 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GFX_H
# define GFX_H

# include <zappy.h>

bool		send_eggs(t_game *game, char **gfx_line, int x, int y);
void		nbr_client(t_game *game, t_client *client);
void		gfx_winner(t_game *game, t_team *team);

# endif