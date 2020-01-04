/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_json_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 10:04:30 by gmohlamo          #+#    #+#             */
/*   Updated: 2020/01/04 10:12:37 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zappy.h>

void		add_json_array(char **str, char *buffer)
{
	char	*temp;
	char	*temp2;

	temp = NULL;
	temp2 = NULL;
	if (*str)
	{
		temp = ft_strdup(", ");
		temp2 = ft_strjoin(*str, temp);
		free(*str);
		free(temp);
		*str = temp2; //these are subsequent objects
	}
	else
		*str = ft_strdup(buffer); //cause this is our first object
}