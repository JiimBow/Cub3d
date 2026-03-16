/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarnier <mgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 09:21:57 by mgarnier          #+#    #+#             */
/*   Updated: 2026/03/16 16:02:29 by mgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx.h"

void	draw_wall(t_mlx *mlx)
{
	int			x;
	int			hit; // passe a 1 quand le rayon touche un wall
	int			side; // verif si on est sur un side wall
	int			map_x; // recup la position x du joueur
	int			map_y; // recup la position y du joueur
	int			step_x; // sert a decaler le point de depart du rayon de 1 ou -1
	int			step_y; // sert a decaler le point de depart du rayon de 1 ou -1
	int			draw_start; // debut de la ligne a dessiner
	int			draw_end; // fin de la ligne a dessiner
	int			line_height; // hauteur de la ligne en fonction de sa distance du joueur
	double		camera_x; // 
	double		ray_dir_x;
	double		ray_dir_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
	mlx_color	color;

	mlx_clear_window(mlx->cont, mlx->win, (mlx_color){0});
	mlx_put_image_to_window(mlx->cont, mlx->win, mlx->background, 0, 0);
	x = 0;
	while (x < SCREEN_WIDTH)
	{
		hit = 0;
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
		while (hit == 0)
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
			if (map_x < 0 || map_x >= SCREEN_WIDTH || map_y < 0 || map_y >= SCREEN_HEIGHT)
				break;
			if (g_world_map[map_y][map_x] > 0)
				hit = 1;
		}
		if (side == 0)
			perp_wall_dist = (side_dist_x - delta_dist_x);
		else
			perp_wall_dist = (side_dist_y - delta_dist_y);
		line_height = (int)(SCREEN_HEIGHT / perp_wall_dist);
		draw_start = -line_height / 2 + SCREEN_HEIGHT / 2;
		if (draw_start < 0)
			draw_start = 0;
		draw_end = line_height / 2 + SCREEN_HEIGHT / 2;
		if (draw_end >= SCREEN_HEIGHT)
			draw_end = SCREEN_HEIGHT - 1;
		if (g_world_map[map_y][map_x] == 1)
			color = (mlx_color){.rgba = RGB_GREEN};
		else if (g_world_map[map_y][map_x] == 2)
			color = (mlx_color){.rgba = RGB_RED};
		else if (g_world_map[map_y][map_x] == 3)
			color = (mlx_color){.rgba = RGB_BLUE};
		else if (g_world_map[map_y][map_x] == 4)
			color = (mlx_color){.rgba = RGB_WHITE};
		else
			color = (mlx_color){.rgba = RGB_YELLOW};
		if (side == 1)
		{
			color.r = (uint8_t)(color.r * 0.7);
			color.g = (uint8_t)(color.g * 0.7);
			color.b = (uint8_t)(color.b * 0.7);
		}
		while (draw_start < draw_end)
			mlx_pixel_put(mlx->cont, mlx->win, x, draw_start++, color);
		x++;
	}
	mlx->old_time = mlx->time;
	mlx->time = get_delta_time(mlx);
	double frame_time = (mlx->time - mlx->old_time) / 1000.0;
	if (frame_time < 0)
		frame_time = 0;
	double rot_speed = frame_time * 3.0;
	if (mlx->keys[79] == 1)
	{
		double	old_dir_x = mlx->dir_x;
		
		mlx->dir_x = mlx->dir_x * cos(-rot_speed) - mlx->dir_y * sin(-rot_speed);
		mlx->dir_y = old_dir_x * sin(-rot_speed) + mlx->dir_y * cos(-rot_speed);
		double old_plane_x = mlx->plane_x;
		mlx->plane_x = mlx->plane_x * cos(-rot_speed) - mlx->plane_y * sin(-rot_speed);
		mlx->plane_y = old_plane_x * sin(-rot_speed) + mlx->plane_y * cos(-rot_speed);
	}
}
