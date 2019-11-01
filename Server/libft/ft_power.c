/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 10:41:07 by gmohlamo          #+#    #+#             */
/*   Updated: 2018/07/03 10:45:22 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long		ft_power(int num, int exp)
{
	long long	ret;

	ret = 1;
	if (!exp)
		return (ret);
	while (exp)
	{
		ret *= num;
		exp--;
	}
	return (ret);
}
