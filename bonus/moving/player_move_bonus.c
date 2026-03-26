/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 14:54:48 by jodone            #+#    #+#             */
/*   Updated: 2026/03/26 09:59:34 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	m_forward(t_mlx *mlx, double *delx, double *dely, double frame_time)
{
	if (mlx->keys[A] == 1)
	{
		*delx = ((mlx->dir_x * frame_time) + (mlx->dir_y * frame_time)) / 2;
		*dely = ((mlx->dir_y * frame_time) + (-mlx->dir_x * frame_time)) / 2;
	}
	else if (mlx->keys[D] == 1)
	{
		*delx = ((mlx->dir_x * frame_time) + (-mlx->dir_x * frame_time)) / 2;
		*dely = ((mlx->dir_y * frame_time) + (-mlx->dir_y * frame_time)) / 2;
	}
	else if (mlx->keys[S] == 1)
	{
		*delx = 0.0;
		*dely = 0.0;
	}
	else
	{
		*delx = mlx->dir_x * frame_time;
		*dely = mlx->dir_y * frame_time;
	}
}

static void	m_back(t_mlx *mlx, double *delx, double *dely, double frame_time)
{
	if (mlx->keys[A] == 1)
	{
		*delx = ((-mlx->dir_x * frame_time) + (mlx->dir_y * frame_time)) / 2;
		*dely = ((-mlx->dir_y * frame_time) + (-mlx->dir_x * frame_time)) / 2;
	}
	else if (mlx->keys[D] == 1)
	{
		*delx = ((-mlx->dir_x * frame_time) + (-mlx->dir_y * frame_time)) / 2;
		*dely = ((-mlx->dir_y * frame_time) + (mlx->dir_x * frame_time)) / 2;
	}
	else if (mlx->keys[W] == 1)
	{
		*delx = 0.0;
		*dely = 0.0;
	}
	else
	{
		*delx = -mlx->dir_x * frame_time;
		*dely = -mlx->dir_y * frame_time;
	}
}

static void	m_right(t_mlx *mlx, double *delx, double *dely, double frame_time)
{
	if (mlx->keys[W] == 1)
	{
		*delx = ((-mlx->dir_y * frame_time) + (mlx->dir_x * frame_time)) / 2;
		*dely = ((mlx->dir_x * frame_time) + (mlx->dir_y * frame_time)) / 2;
	}
	else if (mlx->keys[S] == 1)
	{
		*delx = ((-mlx->dir_x * frame_time) + (-mlx->dir_y * frame_time)) / 2;
		*dely = ((-mlx->dir_y * frame_time) + (mlx->dir_x * frame_time)) / 2;
	}
	else if (mlx->keys[A] == 1)
	{
		*delx = 0.0;
		*dely = 0.0;
	}
	else
	{
		*delx = -mlx->dir_y * frame_time;
		*dely = mlx->dir_x * frame_time;
	}
}

static void	m_left(t_mlx *mlx, double *delx, double *dely, double frame_time)
{
	if (mlx->keys[W] == 1)
	{
		*delx = ((mlx->dir_y * frame_time) + (mlx->dir_x * frame_time)) / 2;
		*dely = ((-mlx->dir_x * frame_time) + (mlx->dir_y * frame_time)) / 2;
	}
	else if (mlx->keys[S] == 1)
	{
		*delx = ((mlx->dir_y * frame_time) + (-mlx->dir_x * frame_time)) / 2;
		*dely = ((-mlx->dir_x * frame_time) + (-mlx->dir_y * frame_time)) / 2;
	}
	else if (mlx->keys[D] == 1)
	{
		*delx = 0.0;
		*dely = 0.0;
	}
	else
	{
		*delx = mlx->dir_y * frame_time;
		*dely = -mlx->dir_x * frame_time;
	}
}

int	player_move(t_mlx *mlx, double delx, double dely, double frame_time)
{
	int		player_x;
	int		player_y;

	if (mlx->keys[W] == 1)
		m_forward(mlx, &delx, &dely, frame_time);
	if (mlx->keys[A] == 1)
		m_left(mlx, &delx, &dely, frame_time);
	if (mlx->keys[S] == 1)
		m_back(mlx, &delx, &dely, frame_time);
	if (mlx->keys[D] == 1)
		m_right(mlx, &delx, &dely, frame_time);
	if (delx > 0)
		player_x = (mlx->pos_x + delx + 0.2);
	else
		player_x = (mlx->pos_x + delx - 0.2);
	if (mlx->s_map->map[(int)mlx->pos_y][player_x] == 'D' && delx != 0.0)
	{
		mlx->s_map->map[(int)mlx->pos_y][player_x] = '0';
	}
	if (mlx->s_map->map[(int)mlx->pos_y][player_x] == '0' && delx != 0.0)
		mlx->pos_x += delx;
	if (dely > 0)
		player_y = (mlx->pos_y + dely + 0.2);
	else
		player_y = (mlx->pos_y + dely - 0.2);
	if (mlx->s_map->map[player_y][(int)mlx->pos_x] == 'D' && dely != 0.0)
		mlx->s_map->map[player_y][(int)mlx->pos_x] = '0';
	if (mlx->s_map->map[player_y][(int)mlx->pos_x] == '0' && dely != 0.0)
		mlx->pos_y += dely;
	return (0);
}
