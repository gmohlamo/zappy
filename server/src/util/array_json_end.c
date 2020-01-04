/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_json_end.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 10:17:27 by gmohlamo          #+#    #+#             */
/*   Updated: 2020/01/04 10:19:35 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zappy.h>

void			array_json_end(char **str)
{
	char		*start = "[ ";
	char		*end = "]";
	char		*temp;

	temp = NULL;
	temp = ft_strjoin(start, *str);
	free(*str);
	*str = ft_strjoin(temp, end);
	free(temp);
}