/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_behavior.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkord <gkord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 15:08:37 by gkord             #+#    #+#             */
/*   Updated: 2022/05/20 16:00:22 by gkord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	enemy_moving_up_down(t_gamedata *data)
{
	if (data->player_pos_y > data->enemy_pos_y && \
	data->map[data->enemy_pos_y + 1][data->enemy_pos_x] == '0')
	{
		data->map[data->enemy_pos_y][data->enemy_pos_x] = '0';
		data->map[data->enemy_pos_y + 1][data->enemy_pos_x] = 'X';
		data->enemy_pos_y++;
	}
	else if (data->player_pos_y < data->enemy_pos_y && \
	data->map[data->enemy_pos_y - 1][data->enemy_pos_x] == '0')
	{
		data->map[data->enemy_pos_y][data->enemy_pos_x] = '0';
		data->map[data->enemy_pos_y - 1][data->enemy_pos_x] = 'X';
		data->enemy_pos_y--;
	}
}

void	enemy_moving_left_right(t_gamedata *data)
{
	if (data->player_pos_x > data->enemy_pos_x && \
	data->map[data->enemy_pos_y][data->enemy_pos_x + 1] == '0')
	{
		data->enemy.direction = 'R';
		data->map[data->enemy_pos_y][data->enemy_pos_x] = '0';
		data->map[data->enemy_pos_y][data->enemy_pos_x + 1] = 'X';
		data->enemy_pos_x++;
	}
	else if (data->player_pos_x < data->enemy_pos_x && \
	data->map[data->enemy_pos_y][data->enemy_pos_x - 1] == '0')
	{
		data->enemy.direction = 'L';
		data->map[data->enemy_pos_y][data->enemy_pos_x] = '0';
		data->map[data->enemy_pos_y][data->enemy_pos_x - 1] = 'X';
		data->enemy_pos_x--;
	}
}
