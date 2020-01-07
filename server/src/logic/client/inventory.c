/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inventory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 18:17:54 by gmohlamo          #+#    #+#             */
/*   Updated: 2020/01/03 22:50:52 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zappy.h>

static void		send_inventory(t_client *client, t_inv *inventory)
{
	char		*str;
	char		*temp;

	temp = NULL;
	str = ft_strjoinint("{linemate ", inventory->linemate_count);
	temp = ft_strjoin(str, ", deraumere ");
	ft_strdel(&str);
	str = ft_strjoinint(temp, inventory->deraumere_count);
	ft_strdel(&temp);
	temp = ft_strjoin(str, ", sibur ");
	ft_strdel(&str);
	str = ft_strjoinint(temp, inventory->sibur_count);
	ft_strdel(&temp);
	temp = ft_strjoin(str, ", mendiane ");
	ft_strdel(&str);
	str = ft_strjoinint(temp, inventory->mendiane_count);
	ft_strdel(&temp);
	temp = ft_strjoin(str, ", phiras ");
	ft_strdel(&str);
	str = ft_strjoinint(temp, inventory->phiras_count);
	ft_strdel(&temp);
	temp = ft_strjoin(str, ", thystame ");
	ft_strdel(&str);
	str = ft_strjoinint(temp, inventory->thystame_count);
	ft_strdel(&temp);
	temp = ft_strjoin(str, ", food ");
	ft_strdel(&str);
	str = ft_strjoinint(temp, inventory->food_count);
	ft_strdel(&temp);
	temp = ft_strjoin(str, "}\n");
	send(client->fd, temp, ft_strlen(temp), MSG_DONTWAIT);
	ft_strdel(&temp);
}

//send inventory information to the client in JSON format
void			inventory_op(t_game *game, t_client *client)
{
	t_list				*lst;
	t_inv				*inventory;

	inventory = client->inventory;
	send_inventory(client, inventory);
	lst = client->lines;
	client->lines = lst->next;
	free(lst->content);
	free(lst);
	client->op = none;
	client->op_complete = true;
}