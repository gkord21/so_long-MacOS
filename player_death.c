/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_death.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkord <gkord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 16:26:16 by gkord             #+#    #+#             */
/*   Updated: 2022/05/20 16:00:03 by gkord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_death_animation(t_gamedata *data)
{
	if (data->player.frame_count == data->player.frames)
		ft_error_exit(data, "YOU DEAD!\n");
	else if (data->player.frame_count <= 5)
		data->player.current_img = data->player.imgd0;
	else if (data->player.frame_count <= 10 && data->player.frame_count > 5)
		data->player.current_img = data->player.imgd1;
	else if (data->player.frame_count <= 15 && data->player.frame_count > 10)
		data->player.current_img = data->player.imgd2;
	else if (data->player.frame_count <= 20 && data->player.frame_count > 15)
		data->player.current_img = data->player.imgd3;
	else if (data->player.frame_count <= 25 && data->player.frame_count > 20)
		data->player.current_img = data->player.imgd4;
	else if (data->player.frame_count <= 30 && data->player.frame_count > 25)
		data->player.current_img = data->space;
	data->player.frame_count += 1;
}
