/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 13:58:09 by gmohlamo          #+#    #+#             */
/*   Updated: 2018/06/15 13:27:15 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_is_space(char c)
{
	if (c == '\n' || c == '\t' || c == '\r' ||
			c == '\v' || c == ' ' || c == '\f')
		return (1);
	return (0);
}

static int		arr_conversion(const char **s, int num, int sign)
{
	char		*str;
	int			exp;

	str = (char*)*s;
	exp = 0;
	while (ft_isdigit(*str) && *str)
	{
		num = num * 10 + (*str - 48);
		str++;
		exp++;
	}
	if (exp > 19 && sign)
		return (0);
	else if (exp > 19 && !sign)
		return (-1);
	else
	{
		if (sign)
			return (num * -1);
		else
			return (num);
	}
}

int				ft_atoi(const char *str)
{
	int			num;
	int			sign;

	num = 0;
	sign = 0;
	while (ft_is_space(*str))
		str++;
	while (*str == '0')
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		sign = 1;
		str++;
	}
	num = arr_conversion(&str, num, sign);
	return (num);
}
