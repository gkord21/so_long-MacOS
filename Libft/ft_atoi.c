/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkord <gkord@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 13:29:36 by gkord             #+#    #+#             */
/*   Updated: 2021/10/27 13:23:20 by gkord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int				i;
	unsigned int	j;
	int				ans;

	i = 1;
	j = 0;
	ans = 0;
	while (str[j] == ' ' || (str[j] >= 9 && str[j] <= 13))
		j++;
	if (str[j] == '+' || str[j] == '-')
	{
		if (str[j] == '+')
			j++;
		else
		{
			i *= -1;
			j++;
		}
	}
	while (str[j] >= '0' && str[j] <= '9')
	{
		ans = ans * 10 + str[j] - 48;
		j++;
	}
	return (ans * i);
}
