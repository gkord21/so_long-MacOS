/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkord <gkord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:49:18 by gkord             #+#    #+#             */
/*   Updated: 2022/05/20 16:31:30 by gkord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_move_score(t_gamedata *data)
{
	char	*score;

	score = ft_itoa(data->move_count);
	mlx_string_put(data->mlx, data->mlx_win, 8, 8, -1, score);
	free(score);
}

void	print_map(t_gamedata *data)
{
	int	i;
	int	j;

	i = -1;
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
		{
			if (data->map[i][j] == '0')
				mlx_put_image_to_window(data->mlx, data->mlx_win, \
										data->space, j * SIZE, i * SIZE);
			if (data->map[i][j] == '1')
				mlx_put_image_to_window(data->mlx, data->mlx_win, \
										data->wall, j * SIZE, i * SIZE);
			if (data->map[i][j] == 'C')
				print_coin(data, i, j);
			if (data->map[i][j] == 'P')
				print_player(data, i, j);
			if (data->map[i][j] == 'E')
				print_exit(data, i, j);
			if (data->map[i][j] == 'X')
				print_enemy(data, i, j);
		}
	}
}

int	render(t_gamedata *data)
{
	if (data->player.direction == 'L' && data->player_death == 0)
		player_animation_left(&data->player);
	else if (data->player.direction == 'R' && data->player_death == 0)
		player_animation_right(&data->player);
	if (data->enemy.direction == 'L')
		enemy_animation_left(&data->enemy);
	else if (data->enemy.direction == 'R')
		enemy_animation_right(&data->enemy);
	if (data->player_death == 1)
		player_death_animation(data);
	item_animation(&data->item);
	mlx_clear_window(data->mlx, data->mlx_win);
	print_map(data);
	print_move_score(data);
	return (0);
}
