/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkord <gkord@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 13:46:55 by gkord             #+#    #+#             */
/*   Updated: 2021/10/23 17:24:26 by gkord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	unsigned char	dc;

	dc = (unsigned char) c;
	if (*str == dc)
		return ((char *)str);
	while (*str++)
	{
		if (*str == dc)
			return ((char *)str);
	}
	return (NULL);
}
