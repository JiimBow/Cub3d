/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarnier <mgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 22:03:15 by mgarnier          #+#    #+#             */
/*   Updated: 2026/03/19 17:05:07 by mgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	fast_sin(double x)
{
	return (x - (x * x * x) * 0.125);
}

double	fast_cos(double x)
{
	return (1 - (x * x) * 0.5);
}

void	player_rotate(t_mlx *mlx, double frame_time, double speed)
{
	double	old_dir_x;
	double	old_plane_x;
	double	cos_speed;
	double	sin_speed;

	if (frame_time < 0)
		frame_time = 0;
	if (mlx->keys[RIGHT_KEY] == 1 || mlx->keys[LEFT_KEY] == 1)
	{
		if (mlx->keys[LEFT_KEY] == 1)
			speed *= -1;
		cos_speed = fast_cos(speed);
		sin_speed = fast_sin(speed);
		old_dir_x = mlx->dir_x;
		mlx->dir_x = mlx->dir_x * cos_speed - mlx->dir_y * sin_speed;
		mlx->dir_y = old_dir_x * sin_speed + mlx->dir_y * cos_speed;
		old_plane_x = mlx->plane_x;
		mlx->plane_x = mlx->plane_x * cos_speed - mlx->plane_y * sin_speed;
		mlx->plane_y = old_plane_x * sin_speed + mlx->plane_y * cos_speed;
	}
	int 	x_mouse;
	int 	y_mouse;
	double	rot;
	double	cos_rot;
	double	sin_rot;
	mlx_mouse_get_pos(mlx->cont, &x_mouse, &y_mouse);
	int delta_x = x_mouse - (SCREEN_WIDTH / 2);
	if (delta_x > -2 && delta_x < 2)
		return ;
	if (delta_x != 0)
	{
		rot = delta_x * 0.002;
		cos_rot = fast_cos(rot);
		sin_rot = fast_sin(rot);
		old_dir_x = mlx->dir_x;
		mlx->dir_x = mlx->dir_x * cos_rot - mlx->dir_y * sin_rot;
		mlx->dir_y = old_dir_x * sin_rot + mlx->dir_y * cos_rot;
		old_plane_x = mlx->plane_x;
		mlx->plane_x = mlx->plane_x * cos_rot - mlx->plane_y * sin_rot;
		mlx->plane_y = old_plane_x * sin_rot + mlx->plane_y * cos_rot;
	}
	mlx_mouse_move(mlx->cont, mlx->win, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
}
