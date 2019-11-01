/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohlamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 14:08:34 by gmohlamo          #+#    #+#             */
/*   Updated: 2018/05/25 13:28:40 by gmohlamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t			ft_numlen(long long n)
{
	size_t				count;

	count = 0;
	while (n)
	{
		n /= 10;
		count++;
	}
	if (count == 0)
		return (1);
	return (count);
}

static char				*return_num(long long n)
{
	char				*str;
	size_t				len;
	long long			rem;

	len = 0;
	rem = 0;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	len += ft_numlen(n);
	if ((str = ft_strnew(len)) == NULL)
		return (NULL);
	if (len > ft_numlen(n))
		str[0] = '-';
	while (n)
	{
		rem = n % 10;
		str[len - 1] = rem + 48;
		n /= 10;
		len--;
	}
	return (str);
}

char					*ft_itoa(int n)
{
	char				*str;
	long long			num;

	num = n;
	str = NULL;
	if (num == 0)
		str = ft_strsub("0", 0, 1);
	else
		str = return_num(num);
	return (str);
}
