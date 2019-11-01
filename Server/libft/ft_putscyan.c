/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putscyan.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 12:48:19 by gmohlamo          #+#    #+#             */
/*   Updated: 2018/06/14 14:33:25 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putscyan(char const *str)
{
	ft_putstr("\033[0;36m");
	ft_putstr(str);
	ft_putstr("\033[0m");
}

void		ft_putscyan_fd(char const *str, int fd)
{
	ft_putstr_fd("\033[0;36m", fd);
	ft_putstr_fd(str, fd);
	ft_putstr_fd("\033[0m", fd);
}
