/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putsblue.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 12:26:14 by gmohlamo          #+#    #+#             */
/*   Updated: 2018/06/14 14:35:41 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putsblue(char const *str)
{
	ft_putstr("\033[0;34m");
	ft_putstr(str);
	ft_putstr("\033[0m");
}

void		ft_putsblue_fd(char const *str, int fd)
{
	ft_putstr_fd("\033[0;34m", fd);
	ft_putstr_fd(str, fd);
	ft_putstr_fd("\033[0m", fd);
}
