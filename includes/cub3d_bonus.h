/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarnier <mgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 11:04:54 by jodone            #+#    #+#             */
/*   Updated: 2026/04/03 12:11:43 by mgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../mlx/includes/mlx.h"
#include "../mlx/includes/mlx_extended.h"
#include "get_next_line.h"
#include "ft_printf.h"
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <math.h>
#include <float.h>

#define W 26
#define A 4
#define S 22
#define D 7
#define E 8
#define R 21
#define M 16
#define RIGHT_KEY 79
#define LEFT_KEY 80
#define DOWN_KEY 81
#define UP_KEY 82
#define ESC 41

#define SCREEN_W 1920
#define SCREEN_H 1080
#define TEX_HEIGHT 512
#define TEX_WIDTH 512
#define SPR_HEIGHT 96
#define SPR_WIDTH 96
#define M_PI 3.14159265358979323846
#define RGB_RED 0xff0000ff
#define SP1_FRAME 10
#define SP2_FRAME 7

typedef struct s_wall
{
	int			tex_x;
	int			tex_y;
	int			step;
	int			side;
	int			map_x;
	int			map_y;
	int			step_x;
	int			step_y;
	int			draw_start;
	int			draw_end;
	double		line_height;
	double		frame_time;
	double		camera_x;
	double		ray_dir_x;
	double		ray_dir_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
	double		wall_x;
	double		tex_pos;

}	t_wall;

typedef struct s_map
{
	char		**map;
	char		**old_map;
	char		*no_path;
	char		*so_path;
	char		*we_path;
	char		*ea_path;
	char		*f_value;
	char		*c_value;
}	t_map;

typedef struct s_text
{
	mlx_image	no_text;
	mlx_image	so_text;
	mlx_image	we_text;
	mlx_image	ea_text;
	mlx_image	do_text;
	mlx_color	f_color;
	mlx_color	c_color;
}	t_text;

typedef struct s_sprite
{
	double	pos_x;
	double	pos_y;
	double	dist;
	mlx_color	samourai_stand[SP1_FRAME][SPR_HEIGHT * SPR_WIDTH];
	mlx_color	samourai_attack[SP2_FRAME][SPR_HEIGHT * SPR_WIDTH];
}	t_sprite;

typedef struct s_draw
{
	int	screen_x;
	int	size;
	int	start_x;
	int	end_x;
	int	start_y;
	int	end_y;
	int	total;
	int	i;
}	t_draw;

typedef struct s_door
{
	int	pos_x;
	int	pos_y;
}	t_door;

typedef struct s_mlx
{
	mlx_context				cont;
	mlx_window				win;
	mlx_window_create_info	info;
	mlx_image				background;
	mlx_image				wall;
	mlx_image				sprite;
	mlx_image				minimap;
	mlx_image				heart;
	mlx_image				heart_broken;
	mlx_image				samourai[2];
	mlx_color				buf_minimap[(SCREEN_H / 10) * (SCREEN_W / 10)];
	mlx_color				*clear;
	mlx_color				*buf_no;
	mlx_color				*buf_so;
	mlx_color				*buf_we;
	mlx_color				*buf_ea;
	mlx_color				*buf_do;
	struct timeval			last_time;
	double					delta;
	double					fps;
	double					fps_timer;
	double					frame_count;
	double					pos_x;
	double					pos_y;
	double					old_pos_x;
	double					old_pos_y;
	double					dir_x;
	double					dir_y;
	double					plane_x;
	double					plane_y;
	double					time;
	double					old_time;
	double					sp_move;
	double					sp_rot;
	int						keys[512];
	int						zoom;
	int						lock_mouse;
	int						door_count;
	int						sprite_count;
	int						frame;
	double					s_timer;
	int						s_frame;
	int						hit;
	int						life;
	double					anim_time;
	mlx_image				dead;
	t_map					*s_map;
	t_text					*s_text;
	t_sprite				*spr;
	t_door					*s_door;
}	t_mlx;

// ERROR
int		error_message(int code);

// Memory Management
void	free_map(t_map *map);
void	free_lst(t_list *lst);
void	free_double_ptr(char **ptr);
void	free_color(t_mlx *mlx);

// PARSING
int		is_space(char c);
int		color_valid(char *str);
int		map_is_not_valid(char *file, t_map *map);
int		check_map(char **map);
int		check_element(t_map *map);
int		is_element(char *map_line, t_list **elem_lst, t_map *map);

// INITIALIZE
void	init_ray_data(t_mlx *mlx, t_wall *ray, int x);
int		init_textures(t_mlx *mlx, t_text *text, t_map *map);
int		init_mlx_struct(t_mlx *mlx, t_map *map, t_text *text, t_door **door);
void	set_mlx_struct(t_mlx *mlx);
int		load_image(t_mlx *mlx, t_text *text, t_map *map);
void	init_door_pos(t_map *map, t_door *door);
int		init_game_count(t_map *map, char type);
void	init_sprite_pos(t_map *map, t_sprite *sprite);

// MOVING
int		set_player_start(t_mlx *mlx, t_map *map);
void	player_rotate(t_mlx *mlx, double frame_time, double speed);
int		player_move(t_mlx *mlx, double delx, double dely, double frame_time);
void	direction_move(t_mlx *mlx, double *delx, double *dely, double frame);
void	open_door(t_mlx *mlx, double player_x, double player_y);

// GRAPHICS
void	draw_wall(t_mlx *mlx);
void	update_frame(void *param);
void	window_hook(int event, void *par);
void	set_background(t_mlx *mlx, t_text *text);

// SPRITE
int		set_sprite_start(t_mlx *mlx);
void	draw_sprites(t_mlx *mlx, double *zbuffer);
void	sort_sprites(t_mlx *mlx, t_sprite *spr, t_sprite *new_spr);
int		get_trans(t_mlx *mlx, t_sprite spr, double *transx, double *transy);
void	def_start_end_x(t_draw *draw);
void	def_start_end_y(t_draw *draw);

// MINIMAP
void	set_minimap(t_mlx *mlx, t_map *map);
void	put_minimap_on_map(t_mlx *mlx);

// KEY
void	key_up(int key, void *param);
void	key_down(int key, void *param);

// TIME
long	get_delta_time(t_mlx *mlx);

// PLAYER_LIFE
void	hitting(void *param);
void	check_player_life(t_mlx *mlx);
