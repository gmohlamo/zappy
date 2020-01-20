/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 16:14:18 by gmohlamo          #+#    #+#             */
/*   Updated: 2020/01/20 23:56:53 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GFX_H
# define GFX_H

# include <zappy.h>

bool		send_eggs(t_game *game, char **gfx_line, int x, int y);
void		nbr_client(t_game *game, t_client *client);
void		gfx_winner(t_game *game, t_team *team);
void		close_incantation_update(t_game *game, char **str);
void		gfx_incantation_update(t_game *game, t_client *client, char  **str);

# endif