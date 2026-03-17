/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 14:54:48 by jodone            #+#    #+#             */
/*   Updated: 2026/03/17 11:28:04 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	player_move(t_mlx *mlx, double delx, double dely)
{
	int		playerX;
	int		playerY;

	// mlx->old_time = mlx->time;
	// mlx->time = get_delta_time(mlx);
	// double frame_time = (mlx->time - mlx->old_time) / 1000.0;
	// if (frame_time < 0)
	// 	frame_time = 0;
	// double rot_speed = frame_time;
	delx = 0.0;
	dely = 0.0;
	mlx->old_time = mlx->time;
	mlx->time = get_delta_time(mlx);
	double frame_time = (mlx->time - mlx->old_time) / 1000.0;
	if (frame_time < 0)
		frame_time = 0;
	double rot_speed = frame_time * 2;
	if (mlx->keys[W] == 1)
	{
		delx = mlx->dir_x * rot_speed;
		dely = mlx->dir_y * rot_speed;
	}
	// if (mlx->keys[A] == 1)
	// {
		
	// }
	if (mlx->keys[S] == 1)
	{
		delx = -mlx->dir_x;
		dely = -mlx->dir_y;
	}
	// if (mlx->keys[D] == 1)
	// {
		
	// }
	playerX = (mlx->pos_x + delx);
	playerY = (mlx->pos_y + dely);
	if (g_world_map[playerY][playerX] == 0.0 && (delx != 0  || dely != 0))
	{
		mlx->pos_x += delx;
		mlx->pos_y += dely;
	}
	return (0);
}
