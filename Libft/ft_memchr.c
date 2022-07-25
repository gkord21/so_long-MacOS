/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkord <gkord@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 13:40:14 by gkord             #+#    #+#             */
/*   Updated: 2021/10/23 16:40:07 by gkord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ds;

	ds = (unsigned char *)s;
	while (n > 0)
	{
		if (*ds == (unsigned char) c)
			return (ds);
		ds++;
		n--;
	}
	return (0);
}
