/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <gmohlamo@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 16:04:11 by gmohlamo          #+#    #+#             */
/*   Updated: 2019/12/17 16:05:13 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zappy.h>

char			*ft_strjoinint(char *str, int n)
{
	char		*temp;
	char		*temp2;

	temp = ft_itoa(n);
	temp2 = ft_strjoin(str, temp);
	free(temp);
	return (temp2);
}