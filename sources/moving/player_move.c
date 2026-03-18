/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 14:54:48 by jodone            #+#    #+#             */
/*   Updated: 2026/03/18 16:06:36 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	wall_collision(t_mlx *mlx, double delx, double dely)
{
	double	new_pos_x;
	double	new_pos_y;

	if (delx > 0)
	{
		new_pos_x = (int)mlx->pos_x + 1;
		if (delx != 0.0 && new_pos_x - (mlx->pos_x + delx) <= 0.2)
			return (1);
	}
	else
	{
		new_pos_x = (int)mlx->pos_x;
		if (delx != 0.0 && (mlx->pos_x + delx) - new_pos_x <= 0.2)
			return (1);
	}
	if (dely > 0)
	{
		new_pos_y = (int)mlx->pos_y + 1;
		if (dely != 0.0 && new_pos_y - (mlx->pos_y + dely) <= 0.2)
			return (1);
	}
	else
	{
		new_pos_y = (int)mlx->pos_y;
		if (dely != 0.0 && (mlx->pos_y + dely) - new_pos_y <= 0.2)
			return (1);
	}
	return (0);
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
	if (delx > 0)
		player_x = (mlx->pos_x + delx + 0.2);
	else
		player_x = (mlx->pos_x + delx - 0.2);
	if (g_world_map[(int)mlx->pos_y][player_x] == 0 && delx != 0.0)
		mlx->pos_x += delx;
	if (dely > 0)
		player_y = (mlx->pos_y + dely + 0.2);
	else
		player_y = (mlx->pos_y + dely - 0.2);
	if (g_world_map[player_y][(int)mlx->pos_x] == 0 && dely != 0.0)
		mlx->pos_y += dely;
	return (0);
}
