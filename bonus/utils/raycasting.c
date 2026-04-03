/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarnier <mgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 15:58:02 by mgarnier          #+#    #+#             */
/*   Updated: 2026/04/03 17:11:12 by mgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	set_textures(t_mlx *mlx, t_wall *ray, int x)
{
	mlx_color	buf[SCREEN_H];
	mlx_color	*col;
	int			i;
	double		step;

	step = 1.0 * TEX_HEIGHT / ray->line_height;
	if (mlx->s_map->map[ray->map_y][ray->map_x] == 'D')
		col = mlx->buf_do;
	else if (ray->step_y < 0 && ray->side == 1)
		col = mlx->buf_no;
	else if (ray->step_y > 0 && ray->side == 1)
		col = mlx->buf_so;
	else if (ray->step_x < 0 && ray->side == 0)
		col = mlx->buf_we;
	else
		col = mlx->buf_ea;
	i = ray->draw_start;
	while (i < ray->draw_end)
	{
		ray->tex_y = (int)ray->tex_pos & (TEX_HEIGHT - 1);
		ray->tex_pos += step;
		buf[i++] = col[ray->tex_x * TEX_WIDTH + ray->tex_y];
	}
	mlx_set_image_region(mlx->cont, mlx->wall, x, ray->draw_start,
		1, ray->line_height, buf + ray->draw_start);
}

void	get_textures(t_mlx *mlx, t_wall *ray)
{
	double	step;

	if (ray->side == 1)
		ray->wall_x = mlx->pos_x + ray->perp_wall_dist * ray->ray_dir_x;
	else
		ray->wall_x = mlx->pos_y + ray->perp_wall_dist * ray->ray_dir_y;
	ray->wall_x -= floor(ray->wall_x);
	ray->tex_x = (int)(ray->wall_x * (double)TEX_WIDTH);
	if ((ray->side == 0 && ray->ray_dir_x > 0)
		|| (ray->side == 1 && ray->ray_dir_y < 0))
		ray->tex_x = TEX_WIDTH - ray->tex_x - 1;
	step = 1.0 * TEX_HEIGHT / ray->line_height;
	ray->tex_pos = (ray->draw_start - (double)SCREEN_H / 2
			+ ray->line_height / 2);
	ray->tex_pos *= step;
}

void	send_ray_until_wall(t_mlx *mlx, t_wall *ray)
{
	while (true)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (mlx->s_map->map[ray->map_y][ray->map_x] != '0'
				&& mlx->s_map->map[ray->map_y][ray->map_x] != 'O'
				&& mlx->s_map->map[ray->map_y][ray->map_x] != '2')
			break ;
	}
}

void	calculate_height_wall(t_wall *ray)
{
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->side_dist_x - ray->delta_dist_x);
	else
		ray->perp_wall_dist = (ray->side_dist_y - ray->delta_dist_y);
	ray->line_height = SCREEN_H / ray->perp_wall_dist;
	ray->draw_start = -ray->line_height * 0.5 + SCREEN_H * 0.5;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height * 0.5 + SCREEN_H * 0.5;
	if (ray->draw_end >= SCREEN_H)
		ray->draw_end = SCREEN_H - 1;
}

void	init_ray_data(t_mlx *mlx, t_wall *ray, int x)
{
	ray->camera_x = 2 * x / (double)SCREEN_W - 1;
	ray->ray_dir_x = mlx->dir_x + mlx->plane_x * ray->camera_x;
	ray->ray_dir_y = mlx->dir_y + mlx->plane_y * ray->camera_x;
	ray->map_x = (int)mlx->pos_x;
	ray->map_y = (int)mlx->pos_y;
	if (ray->ray_dir_x == 0)
		ray->delta_dist_x = 1e30;
	else
		ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	if (ray->ray_dir_y == 0)
		ray->delta_dist_y = 1e30;
	else
		ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
	ray->step_x = (ray->ray_dir_x < 0) * -1 + (ray->ray_dir_x >= 0);
	ray->step_y = (ray->ray_dir_y < 0) * -1 + (ray->ray_dir_y >= 0);
	if (ray->ray_dir_x < 0)
		ray->side_dist_x = (mlx->pos_x - ray->map_x) * ray->delta_dist_x;
	else
		ray->side_dist_x = (ray->map_x + 1.0 - mlx->pos_x) * ray->delta_dist_x;
	if (ray->ray_dir_y < 0)
		ray->side_dist_y = (mlx->pos_y - ray->map_y) * ray->delta_dist_y;
	else
		ray->side_dist_y = (ray->map_y + 1.0 - mlx->pos_y) * ray->delta_dist_y;
}
