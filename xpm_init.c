/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkord <gkord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:24:43 by gkord             #+#    #+#             */
/*   Updated: 2022/05/20 15:01:20 by gkord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	wall_space_exit_init(t_gamedata *data)
{
	int	size;

	size = SIZE;
	data->wall = mlx_xpm_file_to_image(data->mlx, WALL, &size, &size);
	data->space = mlx_xpm_file_to_image(data->mlx, SPACE, &size, &size);
	data->exit_close = mlx_xpm_file_to_image(data->mlx, \
											EXIT_CLOSE, &size, &size);
	data->exit_open = mlx_xpm_file_to_image(data->mlx, \
											EXIT_OPEN, &size, &size);
}

void	item_init(t_gamedata *data)
{
	int	size;

	size = SIZE;
	data->item.frame_count = 0;
	data->item.frames = 31;
	data->item.current_img = mlx_xpm_file_to_image(data->mlx, \
												ITEM0, &size, &size);
	data->item.img0 = mlx_xpm_file_to_image(data->mlx, ITEM0, &size, &size);
	data->item.img1 = mlx_xpm_file_to_image(data->mlx, ITEM1, &size, &size);
	data->item.img2 = mlx_xpm_file_to_image(data->mlx, ITEM2, &size, &size);
	data->item.img3 = mlx_xpm_file_to_image(data->mlx, ITEM3, &size, &size);
	data->item.img4 = mlx_xpm_file_to_image(data->mlx, ITEM4, &size, &size);
	data->item.img5 = mlx_xpm_file_to_image(data->mlx, ITEM5, &size, &size);
}

void	player_init(t_gamedata *data)
{
	int	size;

	size = SIZE;
	data->player.frame_count = 0;
	data->player.frames = 31;
	data->player.direction = 'R';
	data->player.current_img = mlx_xpm_file_to_image(data->mlx, \
													P0R, &size, &size);
	data->player.img0r = mlx_xpm_file_to_image(data->mlx, P0R, &size, &size);
	data->player.img1r = mlx_xpm_file_to_image(data->mlx, P1R, &size, &size);
	data->player.img2r = mlx_xpm_file_to_image(data->mlx, P2R, &size, &size);
	data->player.img3r = mlx_xpm_file_to_image(data->mlx, P3R, &size, &size);
	data->player.img4r = mlx_xpm_file_to_image(data->mlx, P4R, &size, &size);
	data->player.img5r = mlx_xpm_file_to_image(data->mlx, P5R, &size, &size);
	data->player.img0l = mlx_xpm_file_to_image(data->mlx, P0L, &size, &size);
	data->player.img1l = mlx_xpm_file_to_image(data->mlx, P1L, &size, &size);
	data->player.img2l = mlx_xpm_file_to_image(data->mlx, P2L, &size, &size);
	data->player.img3l = mlx_xpm_file_to_image(data->mlx, P3L, &size, &size);
	data->player.img4l = mlx_xpm_file_to_image(data->mlx, P4L, &size, &size);
	data->player.img5l = mlx_xpm_file_to_image(data->mlx, P5L, &size, &size);
	data->player.imgd0 = mlx_xpm_file_to_image(data->mlx, DEATH0, &size, &size);
	data->player.imgd1 = mlx_xpm_file_to_image(data->mlx, DEATH1, &size, &size);
	data->player.imgd2 = mlx_xpm_file_to_image(data->mlx, DEATH2, &size, &size);
	data->player.imgd3 = mlx_xpm_file_to_image(data->mlx, DEATH3, &size, &size);
	data->player.imgd4 = mlx_xpm_file_to_image(data->mlx, DEATH4, &size, &size);
}

void	enemy_init(t_gamedata *data)
{
	int	size;

	size = SIZE;
	data->enemy.frame_count = 0;
	data->enemy.frames = 41;
	data->enemy.direction = 'R';
	data->enemy.current_img = mlx_xpm_file_to_image(data->mlx, \
													ENEMY0R, &size, &size);
	data->enemy.img0r = mlx_xpm_file_to_image(data->mlx, ENEMY0R, &size, &size);
	data->enemy.img1r = mlx_xpm_file_to_image(data->mlx, ENEMY1R, &size, &size);
	data->enemy.img2r = mlx_xpm_file_to_image(data->mlx, ENEMY2R, &size, &size);
	data->enemy.img3r = mlx_xpm_file_to_image(data->mlx, ENEMY3R, &size, &size);
	data->enemy.img0l = mlx_xpm_file_to_image(data->mlx, ENEMY0L, &size, &size);
	data->enemy.img1l = mlx_xpm_file_to_image(data->mlx, ENEMY1L, &size, &size);
	data->enemy.img2l = mlx_xpm_file_to_image(data->mlx, ENEMY2L, &size, &size);
	data->enemy.img3l = mlx_xpm_file_to_image(data->mlx, ENEMY3L, &size, &size);
}
