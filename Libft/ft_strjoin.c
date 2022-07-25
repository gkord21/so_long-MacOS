/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkord <gkord@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 13:48:54 by gkord             #+#    #+#             */
/*   Updated: 2021/10/27 16:19:23 by gkord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*conc_str;
	size_t	i;
	size_t	j;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return ((char *)s2);
	if (!s2)
		return ((char *)s1);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	conc_str = NULL;
	conc_str = (char *)malloc (sizeof(char) * (i + j + 1));
	if (!conc_str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		conc_str[j++] = s1[i++];
	i = 0;
	while (s2[i])
		conc_str[j++] = s2[i++];
	conc_str[j] = '\0';
	return (conc_str);
}
