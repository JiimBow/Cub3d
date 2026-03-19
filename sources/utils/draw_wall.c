/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 09:21:57 by mgarnier          #+#    #+#             */
/*   Updated: 2026/03/19 10:23:22 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

	// int		hit; // passe a 1 quand le rayon touche un wall
	// int		side; // verif si on est sur un side wall
	// int		map_x; // recup la position x du joueur
	// int		map_y; // recup la position y du joueur
	// int		step_x; // sert a decaler le point de depart du rayon de 1 ou -1
	// int		step_y; // sert a decaler le point de depart du rayon de 1 ou -1
	// int		draw_start; // debut de la ligne a dessiner
	// int		draw_end; // fin de la ligne a dessiner
	// int line_height; hauteur de la ligne en fonction de sa distance du joueur
	// double	camera_x; // 
	// double	ray_dir_x;
	// double	ray_dir_y;
	// double	side_dist_x;
	// double	side_dist_y;
	// double	delta_dist_x;
	// double	delta_dist_y;
	// double	perp_wall_dist;

mlx_color	set_color(int step_x, int step_y, int side)
{
	mlx_color	color;

	if (step_y < 0 && side == 1) // VIEW OF SOUTH SIDE
		color = (mlx_color){.rgba = RGB_GREEN};
	else if (step_y > 0 && side == 1) // VIEW OF NORTH SIDE
		color = (mlx_color){.rgba = RGB_RED};
	if (step_x < 0 && side == 0) // VIEW OF EAST SIDE
		color = (mlx_color){.rgba = RGB_BLUE};
	else if (step_x > 0 && side == 0) // VIEW OF WEST SIDE
		color = (mlx_color){.rgba = RGB_WHITE};
	return (color);
}

void	draw_wall(t_mlx *mlx)
{
	int			x;
	int			side;
	int			map_x;
	int			map_y;
	int			step_x;
	int			step_y;
	int			draw_start;
	int			draw_end;
	int			line_height;
	double		frame_time;
	double		camera_x;
	double		ray_dir_x;
	double		ray_dir_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
	mlx_color	color;

	mlx_destroy_image(mlx->cont, mlx->wall);
	mlx->wall = mlx_new_image(mlx->cont, SCREEN_WIDTH, SCREEN_HEIGHT);
	mlx_clear_window(mlx->cont, mlx->win, (mlx_color){0});
	mlx_put_image_to_window(mlx->cont, mlx->win, mlx->background, 0, 0);
	x = 0;
	while (x < SCREEN_WIDTH)
	{
		camera_x = 2 * x / (double)SCREEN_WIDTH - 1;
		ray_dir_x = mlx->dir_x + mlx->plane_x * camera_x;
		ray_dir_y = mlx->dir_y + mlx->plane_y * camera_x;
		map_x = (int)mlx->pos_x;
		map_y = (int)mlx->pos_y;
		if (ray_dir_x == 0)
			delta_dist_x = 1e30;
		else
			delta_dist_x = fabs(1 / ray_dir_x);
		if (ray_dir_y == 0)
			delta_dist_y = 1e30;
		else
			delta_dist_y = fabs(1 / ray_dir_y);
		if (ray_dir_x < 0)
		{
			step_x = -1;
			side_dist_x = (mlx->pos_x - map_x) * delta_dist_x;
		}
		else
		{
			step_x = 1;
			side_dist_x = (map_x + 1.0 - mlx->pos_x) * delta_dist_x;
		}
		if (ray_dir_y < 0)
		{
			step_y = -1;
			side_dist_y = (mlx->pos_y - map_y) * delta_dist_y;
		}
		else
		{
			step_y = 1;
			side_dist_y = (map_y + 1.0 - mlx->pos_y) * delta_dist_y;
		}
		while (true)
		{
			if (side_dist_x < side_dist_y)
			{
				side_dist_x += delta_dist_x;
				map_x += step_x;
				side = 0;
			}
			else
			{
				side_dist_y += delta_dist_y;
				map_y += step_y;
				side = 1;
			}
			if (mlx->s_map->map[map_y][map_x] != '0')
				break ;
		}
		if (side == 0)
			perp_wall_dist = (side_dist_x - delta_dist_x);
		else
			perp_wall_dist = (side_dist_y - delta_dist_y);
		line_height = (int)(SCREEN_HEIGHT / perp_wall_dist);
		draw_start = -line_height * 0.5 + SCREEN_HEIGHT * 0.5;
		if (draw_start < 0)
			draw_start = 0;
		draw_end = line_height * 0.5 + SCREEN_HEIGHT * 0.5;
		if (draw_end >= SCREEN_HEIGHT)
			draw_end = SCREEN_HEIGHT - 1;
		color = set_color(step_x, step_y, side);
		while (draw_start < draw_end)
			mlx_set_image_pixel(mlx->cont, mlx->wall, x, draw_start++, color);
		x++;
	}
	mlx_put_image_to_window(mlx->cont, mlx->win, mlx->wall, 0, 0);
	mlx->old_time = mlx->time;
	mlx->time = get_delta_time(mlx);
	frame_time = (mlx->time - mlx->old_time) * 0.001;
	player_rotate(mlx, frame_time, frame_time * 3.0);
	player_move(mlx, 0.0, 0.0, frame_time * 2.0);
}
