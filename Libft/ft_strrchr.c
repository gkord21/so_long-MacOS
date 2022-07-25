/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkord <gkord@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 13:53:59 by gkord             #+#    #+#             */
/*   Updated: 2021/10/23 18:12:21 by gkord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t			i;
	size_t			ans;
	unsigned char	dc;

	i = 0;
	ans = ft_strlen(str) + 2;
	dc = (unsigned char) c;
	while (i <= ft_strlen(str))
	{
		if (str[i] == dc)
			ans = i;
		i++;
	}
	if (ans == ft_strlen(str) + 2)
		return (NULL);
	else
	{
		while (*str && ans > 0)
		{
			str++;
			ans--;
		}
	}
	return ((char *)str);
}
