/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkord <gkord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 19:27:32 by gkord             #+#    #+#             */
/*   Updated: 2022/05/20 15:00:25 by gkord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_animation_right(t_player *player)
{
	if (player->frame_count == player->frames)
	{
		player->current_img = player->img0r;
		player->frame_count = 0;
	}
	else if (player->frame_count <= 5)
		player->current_img = player->img0r;
	else if (player->frame_count <= 10 && player->frame_count > 5)
		player->current_img = player->img1r;
	else if (player->frame_count <= 15 && player->frame_count > 10)
		player->current_img = player->img2r;
	else if (player->frame_count <= 20 && player->frame_count > 15)
		player->current_img = player->img3r;
	else if (player->frame_count <= 25 && player->frame_count > 20)
		player->current_img = player->img4r;
	else if (player->frame_count <= 30 && player->frame_count > 25)
		player->current_img = player->img5r;
	player->frame_count += 1;
}

void	player_animation_left(t_player *player)
{
	if (player->frame_count == player->frames)
	{
		player->current_img = player->img0l;
		player->frame_count = 0;
	}
	else if (player->frame_count <= 5)
		player->current_img = player->img0l;
	else if (player->frame_count <= 10 && player->frame_count > 5)
		player->current_img = player->img1l;
	else if (player->frame_count <= 15 && player->frame_count > 10)
		player->current_img = player->img2l;
	else if (player->frame_count <= 20 && player->frame_count > 15)
		player->current_img = player->img3l;
	else if (player->frame_count <= 25 && player->frame_count > 20)
		player->current_img = player->img4l;
	else if (player->frame_count <= 30 && player->frame_count > 25)
		player->current_img = player->img5l;
	player->frame_count += 1;
}

void	item_animation(t_item *item)
{
	if (item->frame_count == item->frames)
	{
		item->current_img = item->img0;
		item->frame_count = 0;
	}
	else if (item->frame_count <= 5)
		item->current_img = item->img0;
	else if (item->frame_count <= 10 && item->frame_count > 5)
		item->current_img = item->img1;
	else if (item->frame_count <= 15 && item->frame_count > 10)
		item->current_img = item->img2;
	else if (item->frame_count <= 20 && item->frame_count > 15)
		item->current_img = item->img3;
	else if (item->frame_count <= 25 && item->frame_count > 20)
		item->current_img = item->img4;
	else if (item->frame_count <= 30 && item->frame_count > 25)
		item->current_img = item->img5;
	item->frame_count += 1;
}

void	enemy_animation_left(t_enemy *enemy)
{
	if (enemy->frame_count == enemy->frames)
	{
		enemy->current_img = enemy->img0l;
		enemy->frame_count = 0;
	}
	else if (enemy->frame_count <= 10)
		enemy->current_img = enemy->img0l;
	else if (enemy->frame_count <= 20 && enemy->frame_count > 10)
		enemy->current_img = enemy->img1l;
	else if (enemy->frame_count <= 30 && enemy->frame_count > 20)
		enemy->current_img = enemy->img2l;
	else if (enemy->frame_count <= 40 && enemy->frame_count > 30)
		enemy->current_img = enemy->img3l;
	enemy->frame_count += 1;
}

void	enemy_animation_right(t_enemy *enemy)
{
	if (enemy->frame_count == enemy->frames)
	{
		enemy->current_img = enemy->img0r;
		enemy->frame_count = 0;
	}
	else if (enemy->frame_count <= 10)
		enemy->current_img = enemy->img0r;
	else if (enemy->frame_count <= 20 && enemy->frame_count > 10)
		enemy->current_img = enemy->img1r;
	else if (enemy->frame_count <= 30 && enemy->frame_count > 20)
		enemy->current_img = enemy->img2r;
	else if (enemy->frame_count <= 40 && enemy->frame_count > 30)
		enemy->current_img = enemy->img3r;
	enemy->frame_count += 1;
}
