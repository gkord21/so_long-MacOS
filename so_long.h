/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkord <gkord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 15:56:22 by gkord             #+#    #+#             */
/*   Updated: 2022/05/27 18:44:41 by gkord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx/mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# include "Libft/libft.h"
# include "gnl/get_next_line.h"

enum e_keycode
{
	KEY_UP = 13,
	KEY_DOWN = 1,
	KEY_LEFT = 0,
	KEY_RIGHT = 2,
	ESC = 53
};

typedef struct s_player {
	void	*current_img;
	void	*img0r;
	void	*img1r;
	void	*img2r;
	void	*img3r;
	void	*img4r;
	void	*img5r;
	void	*img0l;
	void	*img1l;
	void	*img2l;
	void	*img3l;
	void	*img4l;
	void	*img5l;
	void	*imgd0;
	void	*imgd1;
	void	*imgd2;
	void	*imgd3;
	void	*imgd4;
	int		frame_count;
	int		frames;
	char	direction;
}	t_player;

typedef struct s_item {
	void	*current_img;
	void	*img0;
	void	*img1;
	void	*img2;
	void	*img3;
	void	*img4;
	void	*img5;
	int		frame_count;
	int		frames;
}	t_item;

typedef struct s_enemy {
	void	*current_img;
	void	*img0r;
	void	*img1r;
	void	*img2r;
	void	*img3r;
	void	*img0l;
	void	*img1l;
	void	*img2l;
	void	*img3l;
	int		frame_count;
	int		frames;
	char	direction;
}	t_enemy;

typedef struct s_gamedata {
	void		*mlx;
	void		*mlx_win;
	char		**map;
	int			map_width;
	int			map_height;
	int			map_line_count;
	int			player_pos_x;
	int			player_pos_y;
	int			enemy_pos_x;
	int			enemy_pos_y;
	int			all_score;
	int			player_score;
	int			h_exit;
	int			move_count;
	void		*wall;
	t_player	player;
	t_item		item;
	t_enemy		enemy;
	void		*exit_close;
	void		*exit_open;
	void		*space;
	int			game_over;
	int			player_death;
}	t_gamedata;

# define P0R		"Texture/player0_right.xpm"
# define P1R		"Texture/player1_right.xpm"
# define P2R		"Texture/player2_right.xpm"
# define P3R		"Texture/player3_right.xpm"
# define P4R		"Texture/player4_right.xpm"
# define P5R		"Texture/player5_right.xpm"
# define P0L		"Texture/player0_left.xpm"
# define P1L		"Texture/player1_left.xpm"
# define P2L		"Texture/player2_left.xpm"
# define P3L		"Texture/player3_left.xpm"
# define P4L		"Texture/player4_left.xpm"
# define P5L		"Texture/player5_left.xpm"
# define WALL		"Texture/wall.xpm"
# define ITEM0		"Texture/item0.xpm"
# define ITEM1		"Texture/item1.xpm"
# define ITEM2		"Texture/item2.xpm"
# define ITEM3		"Texture/item3.xpm"
# define ITEM4		"Texture/item4.xpm"
# define ITEM5		"Texture/item5.xpm"
# define SPACE		"Texture/space.xpm"
# define EXIT_OPEN	"Texture/exit_open.xpm"
# define EXIT_CLOSE	"Texture/exit_close.xpm"
# define ENEMY0R	"Texture/enemy0R.xpm"
# define ENEMY1R	"Texture/enemy1R.xpm"
# define ENEMY2R	"Texture/enemy2R.xpm"
# define ENEMY3R	"Texture/enemy3R.xpm"
# define ENEMY0L	"Texture/enemy0L.xpm"
# define ENEMY1L	"Texture/enemy1L.xpm"
# define ENEMY2L	"Texture/enemy2L.xpm"
# define ENEMY3L	"Texture/enemy3L.xpm"
# define DEATH0		"Texture/death_eff0.xpm"
# define DEATH1		"Texture/death_eff1.xpm"
# define DEATH2		"Texture/death_eff2.xpm"
# define DEATH3		"Texture/death_eff3.xpm"
# define DEATH4		"Texture/death_eff4.xpm"
# define SIZE		32

void		start_game(t_gamedata *data);
t_gamedata	*read_map(char *path, t_gamedata *data);
int			ft_error_exit(t_gamedata *data, char *massage);
int			check_map(t_gamedata *data);
void		print_map(t_gamedata *data);
int			render(t_gamedata *data);
void		move_up(t_gamedata *data);
void		move_down(t_gamedata *data);
void		move_left(t_gamedata *data);
void		move_right(t_gamedata *data);
int			end_game(t_gamedata *data);
void		print_move_score(t_gamedata *data);
void		print_map(t_gamedata *data);
void		wall_space_exit_init(t_gamedata *data);
void		item_init(t_gamedata *data);
void		player_init(t_gamedata *data);
void		enemy_init(t_gamedata *data);
void		add_enemy(t_gamedata *data);
void		player_animation_right(t_player *player);
void		player_animation_left(t_player *player);
void		item_animation(t_item *item);
void		enemy_animation_left(t_enemy *enemy);
void		enemy_animation_right(t_enemy *enemy);
void		enemy_moving_up_down(t_gamedata *data);
void		enemy_moving_left_right(t_gamedata *data);
void		player_death_animation(t_gamedata *data);
void		print_move_score(t_gamedata *data);
void		print_player(t_gamedata *data, int i, int j);
void		print_exit(t_gamedata *data, int i, int j);
void		print_coin(t_gamedata *data, int i, int j);
void		print_enemy(t_gamedata *data, int i, int j);
int			check_width(t_gamedata *data);
int			check_walls(t_gamedata *data);
int			check_coin_exit(t_gamedata *data);
int			check_player(t_gamedata *data);
int			check_symbols(t_gamedata *data);

#endif