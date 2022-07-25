/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkord <gkord@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 13:53:16 by gkord             #+#    #+#             */
/*   Updated: 2021/10/28 12:18:46 by gkord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	n;

	i = 0;
	j = 0;
	n = 0;
	if (!needle[j])
		return ((char *) haystack);
	while (haystack[i] && needle[j] && i < len && len != 0)
	{
		if (haystack[i] == needle[j] && i < len)
		{
			i++;
			j++;
		}
		else if (haystack[i] != needle[j])
		{
			i = ++n;
			j = 0;
		}
	}
	if (j == ft_strlen(needle))
		return (((char *)haystack + (i - ft_strlen(needle))));
	return (NULL);
}
