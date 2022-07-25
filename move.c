/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkord <gkord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:02:10 by gkord             #+#    #+#             */
/*   Updated: 2022/05/20 16:26:14 by gkord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_move_score(t_gamedata *data)
{
	char	*score;

	score = ft_itoa(data->move_count);
	ft_putstr_fd(score, 1);
	ft_putchar_fd('\n', 1);
	free(score);
}

void	move_up(t_gamedata *data)
{
	if (data->map[data->player_pos_y - 1][data->player_pos_x] == 'C')
	{
		data->player_score++;
		data->map[data->player_pos_y][data->player_pos_x] = '0';
		data->map[--data->player_pos_y][data->player_pos_x] = 'P';
	}
	else if (data->map[data->player_pos_y - 1][data->player_pos_x] == 'E'\
			&& data->player_score == data->all_score)
		ft_error_exit(data, "YOU WIN!\n");
	else if (data->map[data->player_pos_y - 1][data->player_pos_x] == 'E'\
			&& data->player_score != data->all_score)
		return ;
	else if (data->map[data->player_pos_y - 1][data->player_pos_x] == '0')
	{
		data->map[data->player_pos_y][data->player_pos_x] = '0';
		data->map[--data->player_pos_y][data->player_pos_x] = 'P';
	}
	else if (data->map[data->player_pos_y - 1][data->player_pos_x] == 'X')
	{	
		data->player.frame_count = 0;
		data->player_death = 1;
	}
	data->move_count++;
	enemy_moving_up_down(data);
	put_move_score(data);
}

void	move_down(t_gamedata *data)
{
	if (data->map[data->player_pos_y + 1][data->player_pos_x] == 'C')
	{
		data->player_score++;
		data->map[data->player_pos_y][data->player_pos_x] = '0';
		data->map[++data->player_pos_y][data->player_pos_x] = 'P';
	}
	else if (data->map[data->player_pos_y + 1][data->player_pos_x] == 'E'\
			&& data->player_score == data->all_score)
		ft_error_exit(data, "YOU WIN!\n");
	else if (data->map[data->player_pos_y + 1][data->player_pos_x] == 'E'\
			&& data->player_score != data->all_score)
		return ;
	else if (data->map[data->player_pos_y + 1][data->player_pos_x] == '0')
	{
		data->map[data->player_pos_y][data->player_pos_x] = '0';
		data->map[++data->player_pos_y][data->player_pos_x] = 'P';
	}
	else if (data->map[data->player_pos_y + 1][data->player_pos_x] == 'X')
	{	
		data->player.frame_count = 0;
		data->player_death = 1;
	}
	data->move_count++;
	enemy_moving_up_down(data);
	put_move_score(data);
}

void	move_left(t_gamedata *data)
{
	if (data->map[data->player_pos_y][data->player_pos_x - 1] == 'C')
	{
		data->player_score++;
		data->map[data->player_pos_y][data->player_pos_x] = '0';
		data->map[data->player_pos_y][--data->player_pos_x] = 'P';
	}
	else if (data->map[data->player_pos_y][data->player_pos_x - 1] == 'E'\
			&& data->player_score == data->all_score)
		ft_error_exit(data, "YOU WIN!\n");
	else if (data->map[data->player_pos_y][data->player_pos_x - 1] == 'E'\
			&& data->player_score != data->all_score)
		return ;
	else if (data->map[data->player_pos_y][data->player_pos_x - 1] == '0')
	{
		data->map[data->player_pos_y][data->player_pos_x] = '0';
		data->map[data->player_pos_y][--data->player_pos_x] = 'P';
	}
	else if (data->map[data->player_pos_y][data->player_pos_x - 1] == 'X')
	{	
		data->player.frame_count = 0;
		data->player_death = 1;
	}
	data->move_count++;
	enemy_moving_left_right(data);
	put_move_score(data);
}

void	move_right(t_gamedata *data)
{
	if (data->map[data->player_pos_y][data->player_pos_x + 1] == 'C')
	{
		data->player_score++;
		data->map[data->player_pos_y][data->player_pos_x] = '0';
		data->map[data->player_pos_y][++data->player_pos_x] = 'P';
	}
	else if (data->map[data->player_pos_y][data->player_pos_x + 1] == 'E'\
		&& data->player_score == data->all_score)
		ft_error_exit(data, "YOU WIN!\n");
	else if (data->map[data->player_pos_y][data->player_pos_x + 1] == 'E'\
		&& data->player_score != data->all_score)
		return ;
	else if (data->map[data->player_pos_y][data->player_pos_x + 1] == '0')
	{
		data->map[data->player_pos_y][data->player_pos_x] = '0';
		data->map[data->player_pos_y][++data->player_pos_x] = 'P';
	}
	else if (data->map[data->player_pos_y][data->player_pos_x + 1] == 'X')
	{	
		data->player.frame_count = 0;
		data->player_death = 1;
	}
	data->move_count++;
	enemy_moving_left_right(data);
	put_move_score(data);
}
