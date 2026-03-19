/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarnier <mgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 22:03:15 by mgarnier          #+#    #+#             */
/*   Updated: 2026/03/19 16:37:38 by mgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	player_rotate(t_mlx *mlx, double frame_time, double speed)
{
	double	old_dir_x;
	double	old_plane_x;

	if (frame_time < 0)
		frame_time = 0;
	if (mlx->keys[RIGHT_KEY] == 1 || mlx->keys[LEFT_KEY] == 1)
	{
		if (mlx->keys[LEFT_KEY] == 1)
			speed *= -1;
		old_dir_x = mlx->dir_x;
		mlx->dir_x = mlx->dir_x * cos(speed) - mlx->dir_y * sin(speed);
		mlx->dir_y = old_dir_x * sin(speed) + mlx->dir_y * cos(speed);
		old_plane_x = mlx->plane_x;
		mlx->plane_x = mlx->plane_x * cos(speed) - mlx->plane_y * sin(speed);
		mlx->plane_y = old_plane_x * sin(speed) + mlx->plane_y * cos(speed);
	}
	int x_mouse;
	int y_mouse;
	double rot;
	mlx_mouse_get_pos(mlx->cont, &x_mouse, &y_mouse);
	int delta_x = x_mouse - (SCREEN_WIDTH / 2);
	if (delta_x > -2 && delta_x < 2)
		return ;
	if (delta_x != 0)
	{
		rot = delta_x * frame_time * 0.1;
		old_dir_x = mlx->dir_x;
		mlx->dir_x = mlx->dir_x * cos(rot) - mlx->dir_y * sin(rot);
		mlx->dir_y = old_dir_x * sin(rot) + mlx->dir_y * cos(rot);
		old_plane_x = mlx->plane_x;
		mlx->plane_x = mlx->plane_x * cos(rot) - mlx->plane_y * sin(rot);
		mlx->plane_y = old_plane_x * sin(rot) + mlx->plane_y * cos(rot);
	}
	mlx_mouse_move(mlx->cont, mlx->win, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
}
