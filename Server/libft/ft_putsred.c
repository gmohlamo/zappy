/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putsred.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 12:18:30 by gmohlamo          #+#    #+#             */
/*   Updated: 2018/08/30 16:12:07 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putsred(char const *str)
{
	ft_putstr("\033[0;31m");
	ft_putstr(str);
	ft_putstr("\033[0m");
}

void		ft_putsred_fd(char const *str, int fd)
{
	ft_putstr_fd("\033[0;31m", fd);
	ft_putstr_fd(str, fd);
	ft_putstr_fd("\033[0m", fd);
}
