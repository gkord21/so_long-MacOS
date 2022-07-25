/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkord <gkord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:22:08 by gkord             #+#    #+#             */
/*   Updated: 2022/05/27 16:05:16 by gkord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map(t_gamedata *data)
{
	int	check;

	check = check_symbols(data);
	check = check_width(data);
	check = check_walls(data);
	check = check_coin_exit(data);
	check = check_player(data);
	if (check != 0)
		return (1);
	return (0);
}
