/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkord <gkord@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 13:50:20 by gkord             #+#    #+#             */
/*   Updated: 2021/10/24 19:27:31 by gkord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	l_src;
	size_t	d_size;

	i = 0;
	l_src = ft_strlen(src);
	d_size = 0;
	if (size == 0)
		return (l_src);
	while (dst[d_size] && d_size < size)
		d_size++;
	if (d_size + 1 > size)
		return (l_src + size);
	while (src[i])
	{
		if (size > d_size + i + 1)
			dst[d_size + i] = src[i];
		i++;
	}
	if (size > d_size + i + 1)
		dst[d_size + i] = '\0';
	else
		dst[size - 1] = '\0';
	return (d_size + i);
}
