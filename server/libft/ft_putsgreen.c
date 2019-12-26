/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putsgreen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 12:32:34 by gmohlamo          #+#    #+#             */
/*   Updated: 2018/08/30 16:10:43 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putsgreen(char const *str)
{
	ft_putstr("\033[0;32m");
	ft_putstr(str);
	ft_putstr("\033[0m");
}

void		ft_putsgreen_fd(char const *str, int fd)
{
	ft_putstr_fd("\033[0;32m", fd);
	ft_putstr_fd(str, fd);
	ft_putstr_fd("\033[0m", fd);
}
