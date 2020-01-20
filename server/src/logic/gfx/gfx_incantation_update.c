/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx_incantation_update.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 23:35:29 by gmohlamo          #+#    #+#             */
/*   Updated: 2020/01/21 00:04:57 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gfx.h>

/*
** close_incantation_update()
** this function will close the json object
*/

void				close_incantation_update(t_game *game, char **str)
{
	char			buffer[1024];
	char			*temp;

	sprintf(buffer, " }\n");
	temp = ft_strjoin(*str, buffer);
	ft_strdel(str);
	*str = temp;
	if (game->gfx > 0)
		send(game->gfx, *str, ft_strlen(*str), MSG_DONTWAIT);
	ft_strdel(str);
}

/*
** gfx_incantation_update()
** updates the gfx to reflect updated client level
*/

void				gfx_incantation_update(t_game *game, t_client *client, char  **str)
{
	char			buffer[1024];
	char			*temp;

	temp = NULL;
	ft_bzero(buffer, sizeof(buffer));
	if (*str == NULL)
	{
		sprintf(buffer, "level_up { client_%zu: %zu", client->nbr, client->level);
		*str = ft_strdup(buffer);
	} else {
		sprintf(buffer, ", client_%zu: %zu", client->nbr, client->level);
		temp = ft_strjoin(*str, buffer);
		ft_strdel(str);
		*str = temp;
	}
}