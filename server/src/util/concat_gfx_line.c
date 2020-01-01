/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concat_gfx_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 16:55:19 by gmohlamo          #+#    #+#             */
/*   Updated: 2020/01/01 13:18:38 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zappy.h>

void		concat_gfx_line(char **gfx_line, char *str)
{
	char	*temp;

	temp = ft_strsafejoin(*gfx_line, str);
	free(str);
	*gfx_line = temp;
}