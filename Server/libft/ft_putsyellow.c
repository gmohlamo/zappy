/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putsyellow.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 12:40:06 by gmohlamo          #+#    #+#             */
/*   Updated: 2018/08/30 16:14:51 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putsyellow(char const *str)
{
	ft_putstr("\033[0;33m");
	ft_putstr(str);
	ft_putstr("\033[0m");
}

void	ft_putsyellow_fd(char const *str, int fd)
{
	ft_putstr_fd("\033[0;33m", fd);
	ft_putstr_fd(str, fd);
	ft_putstr_fd("\033[0m", fd);
}
