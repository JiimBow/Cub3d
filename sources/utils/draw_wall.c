/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarnier <mgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 09:21:57 by mgarnier          #+#    #+#             */
/*   Updated: 2026/03/23 17:02:33 by mgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_textures(t_mlx *mlx, t_wall *ray, int x)
{
	mlx_color	buf[SCREEN_H];
	mlx_color	*col;
	int			i;
	double		step;

	step = 1.0 * TEX_HEIGHT / ray->line_height;
	if (ray->step_y < 0 && ray->side == 1)
		col = mlx->buf_no;
	else if (ray->step_y > 0 && ray->side == 1)
		col = mlx->buf_so;
	if (ray->step_x < 0 && ray->side == 0)
		col = mlx->buf_we;
	else if (ray->step_x > 0 && ray->side == 0)
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

static void	get_textures(t_mlx *mlx, t_wall *ray)
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
	ray->tex_pos = (ray->draw_start - SCREEN_H / 2 + ray->line_height / 2);
	ray->tex_pos *= step;
}

static void	send_ray_until_wall(t_mlx *mlx, t_wall *ray)
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
		if (mlx->s_map->map[ray->map_y][ray->map_x] != '0')
			break ;
	}
}

static void	calculate_height_wall(t_wall *ray)
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

void	draw_wall(t_mlx *mlx)
{
	t_wall	ray;
	int		x;

	mlx_destroy_image(mlx->cont, mlx->wall);
	mlx_destroy_image(mlx->cont, mlx->minimap);
	mlx->wall = mlx_new_image(mlx->cont, SCREEN_W, SCREEN_H);
	mlx->minimap = mlx_new_image(mlx->cont, SCREEN_W / 10, SCREEN_H / 10);
	mlx_clear_window(mlx->cont, mlx->win, (mlx_color){0});
	mlx_put_image_to_window(mlx->cont, mlx->win, mlx->background, 0, 0);
	x = 0;
	while (x < SCREEN_W)
	{
		init_ray_data(mlx, &ray, x);
		send_ray_until_wall(mlx, &ray);
		calculate_height_wall(&ray);
		get_textures(mlx, &ray);
		set_textures(mlx, &ray, x);
		x++;
	}
	mlx_put_image_to_window(mlx->cont, mlx->win, mlx->wall, 0, 0);
	draw_minimap(mlx, &ray);
	mlx->old_time = mlx->time;
	mlx->time = get_delta_time(mlx);
	ray.frame_time = (mlx->time - mlx->old_time) * 0.001;
	player_rotate(mlx, ray.frame_time, ray.frame_time * mlx->sp_rot);
	player_move(mlx, 0.0, 0.0, ray.frame_time * mlx->sp_move);
}
