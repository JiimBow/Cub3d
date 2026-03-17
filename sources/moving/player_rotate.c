/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarnier <mgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 22:03:15 by mgarnier          #+#    #+#             */
/*   Updated: 2026/03/17 22:28:44 by mgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	player_rotate(t_mlx *mlx, double frame_time, double speed)
{
	double	old_dir_x;
	double	old_plane_x;

	if (frame_time < 0)
		frame_time = 0;
	if (mlx->keys[79] == 1)
	{
		old_dir_x = mlx->dir_x;
		mlx->dir_x = mlx->dir_x * cos(speed) - mlx->dir_y * sin(speed);
		mlx->dir_y = old_dir_x * sin(speed) + mlx->dir_y * cos(speed);
		old_plane_x = mlx->plane_x;
		mlx->plane_x = mlx->plane_x * cos(speed) - mlx->plane_y * sin(speed);
		mlx->plane_y = old_plane_x * sin(speed) + mlx->plane_y * cos(speed);
	}
	if (mlx->keys[80] == 1)
	{
		old_dir_x = mlx->dir_x;
		mlx->dir_x = mlx->dir_x * cos(-speed) - mlx->dir_y * sin(-speed);
		mlx->dir_y = old_dir_x * sin(-speed) + mlx->dir_y * cos(-speed);
		old_plane_x = mlx->plane_x;
		mlx->plane_x = mlx->plane_x * cos(-speed) - mlx->plane_y * sin(-speed);
		mlx->plane_y = old_plane_x * sin(-speed) + mlx->plane_y * cos(-speed);
	}
}
