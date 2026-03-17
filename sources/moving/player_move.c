/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarnier <mgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 14:54:48 by jodone            #+#    #+#             */
/*   Updated: 2026/03/17 22:19:34 by mgarnier         ###   ########.fr       */
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
	int		player_x;
	int		player_y;

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
	player_x = (mlx->pos_x + delx);
	if (g_world_map[(int)mlx->pos_y][player_x] == 0.0 && delx != 0)
		mlx->pos_x += delx;
	player_y = (mlx->pos_y + dely);
	if (g_world_map[player_y][(int)mlx->pos_x] == 0.0 && dely != 0)
		mlx->pos_y += dely;
	return (0);
}
