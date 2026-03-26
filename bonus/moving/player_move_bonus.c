/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 14:54:48 by jodone            #+#    #+#             */
/*   Updated: 2026/03/26 16:39:16 by jodone           ###   ########.fr       */
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

void	close_door(t_mlx *mlx, double player_x, double player_y)
{
	double	x_diff;
	double	y_diff;

	x_diff = player_x - mlx->s_door->pos_x;
	y_diff = player_y - mlx->s_door->pos_y;
	if ((-0.5 <= x_diff && x_diff <= 1.5) && (-0.5 <= y_diff && y_diff <= 1.5))
		return ;
	mlx->s_map->map[mlx->s_door->pos_y][mlx->s_door->pos_x] = 'D';
	mlx->s_door->open = 0;
}

int	player_move(t_mlx *mlx, double delx, double dely, double frame_time)
{
	int		player_x;
	int		player_y;
	int		door_x;
	int		door_y;

	if (mlx->keys[W] == 1)
		m_forward(mlx, &delx, &dely, frame_time);
	if (mlx->keys[A] == 1)
		m_left(mlx, &delx, &dely, frame_time);
	if (mlx->keys[S] == 1)
		m_back(mlx, &delx, &dely, frame_time);
	if (mlx->keys[D] == 1)
		m_right(mlx, &delx, &dely, frame_time);
	if (delx > 0)
	{
		player_x = (mlx->pos_x + delx + 0.2);
		door_x = (mlx->pos_x + delx + 1);
	}
	else
	{
		player_x = (mlx->pos_x + delx - 0.2);
		door_x = (mlx->pos_x + delx - 1);
	}
	if (mlx->s_map->map[(int)mlx->pos_y][door_x] == 'D' && delx != 0.0)
	{
		if (mlx->s_door->open == 1)
			close_door(mlx, player_x, mlx->pos_y);
		mlx->s_map->map[(int)mlx->pos_y][door_x] = '0';
		mlx->s_door->second_x = mlx->s_door->pos_x;
		mlx->s_door->second_y = mlx->s_door->pos_y;
		mlx->s_door->pos_x = door_x;
		mlx->s_door->pos_y = (int)mlx->pos_y;
		mlx->s_door->open = 1;
	}
	if (mlx->s_map->map[(int)mlx->pos_y][player_x] == '0' && delx != 0.0)
	{
		mlx->pos_x += delx;
		if (mlx->s_door->open == 1)
			close_door(mlx, player_x, mlx->pos_y);
	}
	if (dely > 0)
	{
		player_y = (mlx->pos_y + dely + 0.5);
		door_y = (mlx->pos_y + dely + 1);
	}
	else
	{
		player_y = (mlx->pos_y + dely - 0.2);
		door_y = (mlx->pos_y + dely - 1);
	}
	if (mlx->s_map->map[door_y][(int)mlx->pos_x] == 'D' && dely != 0.0)
	{
		if (mlx->s_door->open == 1)
			close_door(mlx, mlx->pos_x, player_y);
		mlx->s_map->map[door_y][(int)mlx->pos_x] = '0';
		mlx->s_door->second_x = mlx->s_door->pos_x;
		mlx->s_door->second_y = mlx->s_door->pos_y;
		mlx->s_door->pos_x = (int)mlx->pos_x;
		mlx->s_door->pos_y = door_y;
		mlx->s_door->open = 1;
	}
	if (mlx->s_map->map[player_y][(int)mlx->pos_x] == '0' && dely != 0.0)
	{
		mlx->pos_y += dely;
		if (mlx->s_door->open == 1)
			close_door(mlx, mlx->pos_x, player_y);
	}
	return (0);
}
