/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_enemy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkord <gkord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 18:43:24 by gkord             #+#    #+#             */
/*   Updated: 2022/05/20 14:59:14 by gkord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	add_enemy(t_gamedata *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'E')
			{
				if (data->map[i][j - 1] == '0')
					data->map[i][j - 1] = 'X';
				else if (data->map[i][j + 1] == '0')
					data->map[i][j + 1] = 'X';
				else if (data->map[i - 1][j] == '0')
					data->map[i - 1][j] = 'X';
				else if (data->map[i + 1][j] == '0')
					data->map[i + 1][j] = 'X';
			}
			j++;
		}
		i++;
	}
}
