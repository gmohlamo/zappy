/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concat_resource.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 16:23:36 by gmohlamo          #+#    #+#             */
/*   Updated: 2020/01/01 10:48:19 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zappy.h>

char			*concat_resource(char **str, char *resource)
{
	char		*temp;

	temp = ft_strjoin(*str, resource);
	free(*str);
	*str = temp;
	return (temp);
}