/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 14:54:48 by jodone            #+#    #+#             */
/*   Updated: 2026/03/16 17:05:31 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	player_move(t_mlx *mlx, double delx, double dely)
{
	int	playerX;
	int	playerY;

	playerX = (int)mlx->pos_x;
	playerY = (int)mlx->pos_y;
	// mlx->old_time = mlx->time;
	// mlx->time = get_delta_time(mlx);
	// double frame_time = (mlx->time - mlx->old_time) / 1000.0;
	// if (frame_time < 0)
	// 	frame_time = 0;
	// double rot_speed = frame_time;
	if (mlx->keys[W] == 1)
	{
		delx = mlx->dir_x;
		dely = mlx->dir_y;
	}
	// if (mlx->keys[A] == 1)
	// {
		
	// }
	// if (mlx->keys[S] == 1)
	// {
		
	// }
	// if (mlx->keys[D] == 1)
	// {
		
	// }
	if (g_world_map[playerY + dely][playerX + delx] == 0 && (delx != 0  || dely != 0))
	{
		mlx->pos_x += delx;
		mlx->pos_y += dely;
	}
	return (0);
}
