/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 14:54:48 by jodone            #+#    #+#             */
/*   Updated: 2026/03/17 15:03:02 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	get_move_time(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return ((double)now.tv_sec + (double)now.tv_usec / 1000000.0f);
}

int	player_move(t_mlx *mlx, double delx, double dely, double frame_time)
{
	int		playerX;
	int		playerY;

	if (mlx->keys[W] == 1)
	{
		delx = mlx->dir_x * frame_time;
		dely = mlx->dir_y * frame_time;
	}
	if (mlx->keys[A] == 1)
	{
		delx = mlx->dir_y * frame_time;
		dely = -mlx->dir_x * frame_time;
	}
	if (mlx->keys[S] == 1)
	{
		delx = -mlx->dir_x * frame_time;
		dely = -mlx->dir_y * frame_time;
	}
	if (mlx->keys[D] == 1)
	{
		delx = -mlx->dir_y * frame_time;
		dely = mlx->dir_x * frame_time;
	}
	playerX = (mlx->pos_x + delx);
	if (g_world_map[(int)mlx->pos_y][playerX] == 0.0 && delx != 0)
		mlx->pos_x += delx;
	playerY = (mlx->pos_y + dely);
	if (g_world_map[playerY][(int)mlx->pos_x] == 0.0 && dely != 0)
		mlx->pos_y += dely;
	return (0);
}
