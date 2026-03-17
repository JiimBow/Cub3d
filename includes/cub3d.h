/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 10:55:59 by mgarnier          #+#    #+#             */
/*   Updated: 2026/03/17 14:54:36 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "mlx.h"
#include "mlx_extended.h"
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
#define UP_KEY 81
#define DOWN_KEY 82

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 963
#define RGB_RED 0xff0000ff
#define RGB_GREEN 0x4bff00ff
#define RGB_BLUE 0x0000ffff
#define RGB_WHITE 0xffffffff
#define RGB_YELLOW 0xffff00ff
#define SKY (mlx_color){.rgba = 0x5a96d7ff}
#define GROUND (mlx_color){.rgba = 0xa2a2a2ff}

extern const int	g_world_map[10][10];

typedef struct s_mlx
{
	mlx_context				cont;
	mlx_window				win;
	mlx_window_create_info	info;
	mlx_image				background;
	mlx_image				wall;
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
}	t_mlx;

// ERROR
int			error_message(int code);

// Memory Management
void		free_double_ptr(char **ptr);

// PARSING
int			check_element(char **map);
int			is_element(char *map_line, t_list **elem_lst);
int			map_is_valid(char *map_name);
t_list		*element_init_lst(void);
int			is_space(char c);
int			check_map(char **map);

//MOVING
int			player_move(t_mlx *mlx, double delx, double dely, double frame_time);

void		update_frame(void *param);
void		window_hook(int event, void *par);
void		key_down(int key, void *param);
void		key_up(int key, void *param);
mlx_image	set_background(t_mlx mlx);
void		init_mlx_struct(t_mlx *mlx);
void		draw_wall(t_mlx *mlx);
long		get_delta_time(t_mlx *mlx);
double		get_move_time(void);
