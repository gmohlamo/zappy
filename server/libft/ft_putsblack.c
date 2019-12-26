/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putsblack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 12:36:27 by gmohlamo          #+#    #+#             */
/*   Updated: 2018/06/14 14:33:05 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putsblack(char const *str)
{
	ft_putstr("\033[0;30m");
	ft_putstr(str);
	ft_putstr("\033[0m");
}

void	ft_putsblack_fd(char const *str, int fd)
{
	ft_putstr_fd("\033[0;30m", fd);
	ft_putstr_fd(str, fd);
	ft_putstr_fd("\033[0m", fd);
}
