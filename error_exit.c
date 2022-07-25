/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkord <gkord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 17:59:24 by gkord             #+#    #+#             */
/*   Updated: 2022/05/27 16:06:42 by gkord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_error_exit(t_gamedata *data, char *massage)
{
	int	i;

	i = 0;
	if (massage != NULL)
		ft_putstr_fd(massage, 2);
	else
		ft_putstr_fd("Error\n", 2);
	if (data->map != NULL)
	{
		if (data->map[i])
		{
			while (data->map[i])
				free(data->map[i++]);
		}
		free(data->map);
	}
	if (data->mlx && data->mlx_win)
	{
		mlx_clear_window(data->mlx, data->mlx_win);
		mlx_destroy_window(data->mlx, data->mlx_win);
	}
	if (data)
		free(data);
	exit(0);
	return (0);
}
