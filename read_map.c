/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkord <gkord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 16:05:22 by gkord             #+#    #+#             */
/*   Updated: 2022/05/27 16:15:36 by gkord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	line_count(t_gamedata *data, char *path)
{
	char	*buff;
	int		count;
	int		fd;

	count = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_error_exit(data, "FD ERROR\n");
	buff = get_next_line(fd);
	while (buff != NULL)
	{
		count++;
		free(buff);
		buff = get_next_line(fd);
	}
	close (fd);
	return (count);
}

t_gamedata	*ft_reading(t_gamedata *data, int fd)
{
	int		j;
	int		i;
	int		count;
	char	*buff;

	i = 0;
	buff = get_next_line(fd);
	while (buff != NULL)
	{
		j = 0;
		count = 0;
		data->map[i] = (char *)malloc(sizeof(char) * (ft_strlen_gnl(buff) + 1));
		while (buff[count] != '\0')
		{
			data->map[i][j] = buff[count];
			j++;
			count++;
		}
		data->map[i][j] = '\0';
		i++;
		free (buff);
		buff = get_next_line(fd);
	}
	free(buff);
	return (data);
}

t_gamedata	*read_map(char *path, t_gamedata *data)
{
	int		fd;

	data->map_line_count = line_count(data, path);
	data->map = (char **)malloc(sizeof(char *) * (data->map_line_count + 1));
	if (!data->map)
		ft_error_exit(data, "MALLOC ERROR FOR MAP\n");
	data->map[data->map_line_count] = NULL;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		ft_error_exit(data, "FD ERROR\n");
	data = ft_reading(data, fd);
	close(fd);
	if (check_map(data))
		return (NULL);
	add_enemy(data);
	return (data);
}
