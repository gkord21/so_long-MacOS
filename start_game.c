/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkord <gkord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 17:54:01 by gkord             #+#    #+#             */
/*   Updated: 2022/05/20 16:25:23 by gkord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	keyhook(int keycode, t_gamedata *data)
{
	if (keycode == ESC)
		ft_error_exit(data, "GAME OVER\n");
	else if (keycode == KEY_UP && \
			data->map[data->player_pos_y - 1][data->player_pos_x] != '1' \
			&& data->player_death == 0)
		move_up(data);
	else if (keycode == KEY_LEFT && \
			data->map[data->player_pos_y][data->player_pos_x - 1] != '1' \
			&& data->player_death == 0)
	{
		data->player.direction = 'L';
		move_left(data);
	}
	else if (keycode == KEY_DOWN && \
			data->map[data->player_pos_y + 1][data->player_pos_x] != '1' \
			&& data->player_death == 0)
		move_down(data);
	else if (keycode == KEY_RIGHT && \
			data->map[data->player_pos_y][data->player_pos_x + 1] != '1' \
			&& data->player_death == 0)
	{
		data->player.direction = 'R';
		move_right(data);
	}
	return (0);
}

void	start_game(t_gamedata *data)
{
	data->mlx = mlx_init();
	if (data->mlx != NULL)
	{
		data->mlx_win = mlx_new_window(data->mlx, data->map_width * SIZE, \
									data->map_height * SIZE, "So_long");
		if (data->mlx_win != NULL)
		{
			wall_space_exit_init(data);
			item_init(data);
			player_init(data);
			enemy_init(data);
			print_map(data);
			mlx_hook(data->mlx_win, 2, 0, keyhook, data);
			mlx_hook(data->mlx_win, 17, 0, ft_error_exit, data);
			mlx_loop_hook(data->mlx, render, (void *)data);
			mlx_loop(data->mlx);
		}
		else
			ft_error_exit(data, "MLX ERROR\n");
	}
	else
		ft_error_exit(data, "MLX ERROR\n");
}
