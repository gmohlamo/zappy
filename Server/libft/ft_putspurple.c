/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putspurple.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 12:43:39 by gmohlamo          #+#    #+#             */
/*   Updated: 2018/08/30 16:12:19 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putspurple(char const *str)
{
	ft_putstr("\033[0;35m");
	ft_putstr(str);
	ft_putstr("\033[0m");
}

void		ft_putspurple_fd(char const *str, int fd)
{
	ft_putstr_fd("\033[0;35m", fd);
	ft_putstr_fd(str, fd);
	ft_putstr_fd("\033[0m", fd);
}
