/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarnier <mgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 09:21:57 by mgarnier          #+#    #+#             */
/*   Updated: 2026/04/06 18:07:06 by mgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	check_player_movement(t_mlx *mlx, t_wall *ray)
{
	mlx->old_time = mlx->time;
	mlx->time = get_delta_time(mlx);
	ray->frame_time = (mlx->time - mlx->old_time) * 0.001;
	if (ray->frame_time > 0.5)
		ray->frame_time = 0.5;
	if (mlx->life > 0)
		player_move(mlx, 0.0, 0.0, ray->frame_time * mlx->sp_move);
	else
	{
		if (mlx->frame < 30)
			mlx_put_transformed_image_to_window(mlx->cont, mlx->win, mlx->dead1,
				SCREEN_W / 2 - TEX_WIDTH, SCREEN_H / 2 - TEX_HEIGHT, 2, 2, 0);
		else
			mlx_put_transformed_image_to_window(mlx->cont, mlx->win, mlx->dead2,
				SCREEN_W / 2 - TEX_WIDTH, SCREEN_H / 2 - TEX_HEIGHT, 2, 2, 0);
		mlx->keys[RIGHT_KEY] = 1;
		mlx->keys[LEFT_KEY] = 0;
		mlx->lock_mouse = 1;
		mlx_mouse_show(mlx->cont);
	}
	player_rotate(mlx, ray->frame_time, ray->frame_time * mlx->sp_rot);
}

static void	raycasting(t_mlx *mlx, t_wall *ray, double *zbuffer)
{
	int	x;

	mlx->frame = (mlx->frame + 1) % 100;
	mlx->s_timer += mlx->delta;
	if (mlx->s_timer >= 0.00001)
	{
		mlx->s_frame++;
		mlx->s_timer = 0;
	}
	x = 0;
	while (x < SCREEN_W)
	{
		init_ray_data(mlx, ray, x);
		send_ray_until_wall(mlx, ray);
		calculate_height_wall(ray);
		zbuffer[x] = ray->perp_wall_dist;
		get_textures(mlx, ray);
		set_textures(mlx, ray, x);
		x++;
	}
}

void	draw_wall(t_mlx *mlx)
{
	t_wall	ray;
	double	zbuffer[SCREEN_W];

	mlx_destroy_image(mlx->cont, mlx->wall);
	if (mlx->sprite_count != 0)
		mlx_destroy_image(mlx->cont, mlx->sprite);
	mlx->wall = mlx_new_image(mlx->cont, SCREEN_W, SCREEN_H);
	mlx_clear_window(mlx->cont, mlx->win, (mlx_color){0});
	mlx_put_image_to_window(mlx->cont, mlx->win, mlx->background, 0, 0);
	raycasting(mlx, &ray, zbuffer);
	mlx_put_image_to_window(mlx->cont, mlx->win, mlx->wall, 0, 0);
	if (mlx->sprite_count != 0)
	{
		mlx->sprite = mlx_new_image(mlx->cont, SCREEN_W, SCREEN_H);
		draw_sprites(mlx, zbuffer);
		mlx_put_image_to_window(mlx->cont, mlx->win, mlx->sprite, 0, 0);
	}
	put_minimap_on_map(mlx);
	check_player_life(mlx);
	check_player_movement(mlx, &ray);
}
