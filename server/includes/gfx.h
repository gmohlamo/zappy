/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 16:14:18 by gmohlamo          #+#    #+#             */
/*   Updated: 2019/12/20 14:52:12 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GFX_H
# define GFX_H

# include <zappy.h>

void		send_eggs(t_game *game, int x, int y);
void		nbr_client(t_game *game, t_client *client);

# endif