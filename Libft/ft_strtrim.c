/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkord <gkord@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 13:54:50 by gkord             #+#    #+#             */
/*   Updated: 2021/10/27 16:20:26 by gkord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	begin;
	size_t	end;
	char	*res;
	size_t	i;

	if (!set)
		return ((char *)s1);
	if (!s1)
		return (NULL);
	end = ft_strlen(s1);
	begin = 0;
	i = 0;
	while (s1[begin] && ft_check_set(s1[begin], set))
		begin++;
	while (end > begin && ft_check_set(s1[end - 1], set))
		end--;
	res = (char *)malloc(sizeof(char) * (end - begin + 1));
	if (!res)
		return (NULL);
	while (begin < end)
		res[i++] = s1[begin++];
	res[i] = '\0';
	return (res);
}
