/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkord <gkord@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 13:46:21 by gkord             #+#    #+#             */
/*   Updated: 2021/10/27 16:14:14 by gkord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_num_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
		{
			while (s[i] != c && s[i])
				i++;
			count++;
		}
	}
	return (count);
}

static size_t	ft_strlen_mod(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	**ft_error_free(char **res)
{
	size_t	i;

	i = 0;
	while (res[i])
	{
		free(res[i]);
		i++;
	}
	free(res);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	i;
	size_t	index_w;

	if (!s)
		return (NULL);
	res = (char **)malloc(sizeof(char *) * (ft_num_words(s, c) + 1));
	if (!res)
		return (NULL);
	i = 0;
	index_w = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			res[index_w] = ft_substr(s, i, ft_strlen_mod(s + i, c));
			if (!res)
				return (ft_error_free(res));
			i = i - 1 + ft_strlen_mod(s + i, c);
			index_w++;
		}
		i++;
	}
	res[index_w] = NULL;
	return (res);
}
