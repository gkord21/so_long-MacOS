/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkord <gkord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 15:56:09 by gkord             #+#    #+#             */
/*   Updated: 2022/05/20 14:55:49 by gkord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_gamedata	*init_data(void)
{
	t_gamedata	*data;

	data = malloc(sizeof(t_gamedata));
	if (!data)
		ft_error_exit(data, "MALLOC ERROR FOR DATA\n");
	data->player_score = 0;
	data->game_over = 0;
	data->h_exit = 0;
	data->all_score = 0;
	data->player_pos_x = 0;
	data->player_pos_y = 0;
	data->enemy_pos_x = 0;
	data->enemy_pos_y = 0;
	data->player_death = 0;
	return (data);
}

int	check_file(char *path)
{
	if (ft_strnstr(path, ".ber", ft_strlen(path)) != NULL)
		return (0);
	else
		return (1);
}

int	main(int argc, char **argv)
{
	t_gamedata	*data;

	if (argc == 2)
	{
		data = init_data();
		if (!check_file(argv[1]))
			read_map(argv[1], data);
		else
			ft_error_exit(data, "FILE ERROR\n");
		start_game(data);
	}
	else
		ft_putstr_fd("ERROR!\n", 2);
	return (0);
}
