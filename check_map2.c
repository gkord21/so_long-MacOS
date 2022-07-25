/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkord <gkord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:16:12 by gkord             #+#    #+#             */
/*   Updated: 2022/05/27 16:05:29 by gkord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_width(t_gamedata *data)
{
	int	i;
	int	j;
	int	width;
	int	count;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		count = 0;
		while (data->map[i][j])
		{
			j++;
			if (data->map[i][j] != '\0' && data->map[i][j] != '\n')
				count++;
		}
		if (i == 0)
			width = count;
		if (count != width)
			ft_error_exit(data, "ERROR! Check width or height of map.\n");
		i++;
	}
	data->map_height = i;
	data->map_width = width + 1;
	return (0);
}

int	check_walls(t_gamedata *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		if (i > 0 && i < data->map_height - 1 && (data->map[i][0] != '1' \
			|| data->map[i][data->map_width - 1] != '1'))
			ft_error_exit(data, "ERROR! Check walls in map.\n");
		while (data->map[i][j])
		{
			if (data->map[i][j] != '\0' && data->map[i][j] != '\n' && \
				((i == 0 && data->map[i][j] != '1') || \
				(i == data->map_height - 1 && data->map[i][j] != '1')))
				ft_error_exit(data, "ERROR! First or last line not correct.\n");
			j++;
		}
		i++;
	}
	return (0);
}

int	check_coin_exit(t_gamedata *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'C')
				data->all_score++;
			if (data->map[i][j] == 'E')
				data->h_exit++;
			j++;
		}
		i++;
	}
	if (data->all_score == 0 || data->h_exit == 0)
		ft_error_exit(data, "ERROR! Map has not C or E.\n");
	return (0);
}

int	check_player(t_gamedata *data)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P')
			{
				data->player_pos_x = j;
				data->player_pos_y = i;
				count++;
			}
			j++;
		}
		i++;
	}
	if ((data->player_pos_y == 0 && data->player_pos_x == 0) || count > 1)
		ft_error_exit(data, "ERROR! Check player.\n");
	return (0);
}

int	check_symbols(t_gamedata *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] != '1' && data->map[i][j] != '0' && \
				data->map[i][j] != 'P' && data->map[i][j] != 'E' && \
				data->map[i][j] != 'C' && data->map[i][j] != '\n' && \
				data->map[i][j] != '\0')
				ft_error_exit(data, \
				"ERROR! Map can consist only of 0, 1, C, P, E\n");
			j++;
		}
		i++;
	}
	return (0);
}
