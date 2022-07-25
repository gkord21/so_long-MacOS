/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_xpm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkord <gkord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 15:16:57 by gkord             #+#    #+#             */
/*   Updated: 2022/05/20 15:51:49 by gkord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_player(t_gamedata *data, int i, int j)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win, \
							data->space, j * SIZE, i * SIZE);
	mlx_put_image_to_window(data->mlx, data->mlx_win, \
							data->player.current_img, j * SIZE, i * SIZE);
	data->player_pos_x = j;
	data->player_pos_y = i;
}

void	print_exit(t_gamedata *data, int i, int j)
{
	if (data->player_score == data->all_score)
		mlx_put_image_to_window(data->mlx, data->mlx_win, \
								data->exit_open, j * SIZE, i * SIZE);
	else
		mlx_put_image_to_window(data->mlx, data->mlx_win, \
								data->exit_close, j * SIZE, i * SIZE);
}

void	print_coin(t_gamedata *data, int i, int j)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win, \
							data->space, j * SIZE, i * SIZE);
	mlx_put_image_to_window(data->mlx, data->mlx_win, \
							data->item.current_img, j * SIZE, i * SIZE);
}

void	print_enemy(t_gamedata *data, int i, int j)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win, \
							data->space, j * SIZE, i * SIZE);
	mlx_put_image_to_window(data->mlx, data->mlx_win, \
							data->enemy.current_img, j * SIZE, i * SIZE);
	data->enemy_pos_x = j;
	data->enemy_pos_y = i;
}
