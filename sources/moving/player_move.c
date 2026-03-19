/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 14:54:48 by jodone            #+#    #+#             */
/*   Updated: 2026/03/19 11:11:46 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	player_move(t_mlx *mlx, double delx, double dely, double frame_time)
{
	int		player_x;
	int		player_y;

	if (mlx->keys[W] == 1)
	{
		if (mlx->keys[A] == 1)
		{
			delx = ((mlx->dir_x * frame_time) + (mlx->dir_y * frame_time)) / 2;
			dely = ((mlx->dir_y * frame_time) + (-mlx->dir_x * frame_time)) / 2;
		}
		else if (mlx->keys[D] == 1)
		{
			delx = ((mlx->dir_x * frame_time) + (-mlx->dir_x * frame_time)) / 2;
			dely = ((mlx->dir_y * frame_time) + (-mlx->dir_y * frame_time)) / 2;
		}
		else if (mlx->keys[S] == 1)
		{
			delx = 0.0;
			dely = 0.0;
		}
		else
		{
			delx = mlx->dir_x * frame_time;
			dely = mlx->dir_y * frame_time;
		}
	}
	if (mlx->keys[A] == 1)
	{
		if (mlx->keys[W] == 1)
		{
			delx = ((mlx->dir_y * frame_time) + (mlx->dir_x * frame_time)) / 2;
			dely = ((-mlx->dir_x * frame_time) + (mlx->dir_y * frame_time)) / 2;
		}
		else if (mlx->keys[S] == 1)
		{
			delx = ((mlx->dir_y * frame_time) + (-mlx->dir_x * frame_time)) / 2;
			dely = ((-mlx->dir_x * frame_time) + (-mlx->dir_y * frame_time)) / 2;
		}
		else if (mlx->keys[D] == 1)
		{
			delx = 0.0;
			dely = 0.0;
		}
		else
		{
			delx = mlx->dir_y * frame_time;
			dely = -mlx->dir_x * frame_time;
		}
	}
	if (mlx->keys[S] == 1)
	{
		if (mlx->keys[A] == 1)
		{
			delx = ((-mlx->dir_x * frame_time) + (mlx->dir_y * frame_time)) / 2;
			dely = ((-mlx->dir_y * frame_time) + (-mlx->dir_x * frame_time)) / 2;
		}
		else if (mlx->keys[D] == 1)
		{
			delx = ((-mlx->dir_x * frame_time) + (-mlx->dir_y * frame_time)) / 2;
			dely = ((-mlx->dir_y * frame_time) + (mlx->dir_x * frame_time)) / 2;
		}
		else if (mlx->keys[W] == 1)
		{
			delx = 0.0;
			dely = 0.0;
		}
		else
		{
			delx = -mlx->dir_x * frame_time;
			dely = -mlx->dir_y * frame_time;
		}
	}
	if (mlx->keys[D] == 1)
	{
		if (mlx->keys[W] == 1)
		{
			delx = ((-mlx->dir_y * frame_time) + (mlx->dir_x * frame_time)) / 2;
			dely = ((mlx->dir_x * frame_time) + (mlx->dir_y * frame_time)) / 2;
		}
		else if (mlx->keys[S] == 1)
		{
			delx = ((-mlx->dir_x * frame_time) + (-mlx->dir_y * frame_time)) / 2;
			dely = ((-mlx->dir_y * frame_time) + (mlx->dir_x * frame_time)) / 2;
		}
		else if (mlx->keys[A] == 1)
		{
			delx = 0.0;
			dely = 0.0;
		}
		else
		{
			delx = -mlx->dir_y * frame_time;
			dely = mlx->dir_x * frame_time;
		}
	}
	if (delx > 0)
		player_x = (mlx->pos_x + delx + 0.2);
	else
		player_x = (mlx->pos_x + delx - 0.2);
	if (mlx->s_map->map[(int)mlx->pos_y][player_x] == '0' && delx != 0.0)
		mlx->pos_x += delx;
	if (dely > 0)
		player_y = (mlx->pos_y + dely + 0.2);
	else
		player_y = (mlx->pos_y + dely - 0.2);
	if (mlx->s_map->map[player_y][(int)mlx->pos_x] == '0' && dely != 0.0)
		mlx->pos_y += dely;
	return (0);
}
