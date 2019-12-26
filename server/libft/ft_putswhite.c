/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putswhite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 12:52:01 by gmohlamo          #+#    #+#             */
/*   Updated: 2018/08/30 16:16:32 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putswhite(char const *str)
{
	ft_putstr("\033[0;37m");
	ft_putstr(str);
	ft_putstr("\033[0m");
}

void		ft_putswhite_fd(char const *str, int fd)
{
	ft_putstr_fd("\033[0;37m", fd);
	ft_putstr_fd(str, fd);
	ft_putstr_fd("\033[0m", fd);
}
