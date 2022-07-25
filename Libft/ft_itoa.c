/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkord <gkord@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 13:39:07 by gkord             #+#    #+#             */
/*   Updated: 2021/10/27 19:50:55 by gkord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_res_itoa(char *res, int n, int i)
{
	if (n >= 10)
	{
		ft_res_itoa(res, n / 10, i);
		ft_res_itoa(res, n % 10, i);
	}
	else
	{
		while (res[i] != '\0')
			i++;
		res[i] = n + '0';
		return (res);
	}
	return (res);
}

static size_t	ft_num10(int n)
{
	size_t	size;

	size = 1;
	if (n < 0)
	{
		n = -n;
		size++;
	}
	while (n / 10 > 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*res;
	size_t	size;
	size_t	i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	size = ft_num10(n);
	res = (char *)malloc(sizeof(char) * (size + 1));
	if (!res)
		return (NULL);
	res = ft_memset(res, '\0', size + 1);
	i = 0;
	if (n < 0)
	{
		res[0] = '-';
		n = -n;
		i++;
	}
	res = ft_res_itoa(res, n, i);
	return (res);
}
