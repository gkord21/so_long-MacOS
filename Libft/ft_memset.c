/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkord <gkord@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 13:43:07 by gkord             #+#    #+#             */
/*   Updated: 2021/10/27 12:07:24 by gkord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *mass, int c, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)mass;
	while (i < n)
	{
		str[i] = c;
		i++;
	}
	return (mass);
}
