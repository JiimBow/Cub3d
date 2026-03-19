/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarnier <mgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 10:55:59 by mgarnier          #+#    #+#             */
/*   Updated: 2026/03/19 14:44:36 by mgarnier         ###   ########.fr       */
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

#define W 26
#define A 4
#define S 22
#define D 7
#define RIGHT_KEY 79
#define LEFT_KEY 80

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080
#define tex_height 64
#define tex_width 64
#define RGB_RED 0xff0000ff
#define RGB_GREEN 0x4bff00ff
#define RGB_BLUE 0x0000ffff
#define RGB_WHITE 0xffffffff
#define RGB_YELLOW 0xffff00ff
#define SKY 0x5a96d7ff
#define GROUND 0xa2a2a2ff

typedef struct s_map
{
	char		**map;
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
	mlx_color	f_color;
	mlx_color	c_color;
}	t_text;

typedef struct s_mlx
{
	mlx_context				cont;
	mlx_window				win;
	mlx_window_create_info	info;
	mlx_image				background;
	mlx_image				wall;
	mlx_image				north;
	struct timeval			last_time;
	double					delta;
	double					fps;
	double					fps_timer;
	double					frame_count;
	double					pos_x;
	double					pos_y;
	double					dir_x;
	double					dir_y;
	double					plane_x;
	double					plane_y;
	double					time;
	double					old_time;
	int						keys[512];
	t_map					*s_map;
	t_text					*s_text;
}	t_mlx;

// ERROR
int		error_message(int code);

// Memory Management
void	free_double_ptr(char **ptr);

// PARSING
int		check_element(t_map *map);
int		is_element(char *map_line, t_list **elem_lst, t_map *map);
int		map_is_valid(char *file, t_map *map);
t_list	*element_init_lst(void);
int		is_space(char c);
int		check_map(char **map);
int		init_textures(t_mlx *mlx, t_text *text, t_map *map);

//MOVING
int		player_move(t_mlx *mlx, double delx, double dely, double frame_time);
void	player_rotate(t_mlx *mlx, double frame_time, double speed);

void	update_frame(void *param);
void	window_hook(int event, void *par);
void	key_down(int key, void *param);
void	key_up(int key, void *param);
void	set_background(t_mlx *mlx, t_text *text);
void	init_mlx_struct(t_mlx *mlx, t_map *map, t_text *text);
void	draw_wall(t_mlx *mlx);
long	get_delta_time(t_mlx *mlx);
