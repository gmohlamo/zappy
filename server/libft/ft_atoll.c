/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 11:44:20 by gmohlamo          #+#    #+#             */
/*   Updated: 2018/08/24 11:49:12 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_is_space(char c)
{
	if (c == '\n' || c == '\t' || c == '\r' ||
			c == '\v' || c == ' ' || c == '\f')
		return (1);
	return (0);
}

static long long	arr_conversion(const char **s, long long num, int sign)
{
	char			*str;

	str = (char*)*s;
	while (ft_isdigit(*str) && *str)
	{
		num = num * 10 + (*str - 48);
		str++;
	}
	return (num * sign);
}

long long			ft_atoll(const char *str)
{
	long long		num;
	int				sign;

	num = 0;
	sign = 1;
	while (ft_is_space(*str))
		str++;
	while (*str == '0')
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		sign = -1;
		str++;
	}
	num = arr_conversion(&str, num, sign);
	return (num);
}
