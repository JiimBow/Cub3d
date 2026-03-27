/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 11:33:42 by jodone            #+#    #+#             */
/*   Updated: 2026/03/27 12:10:13 by jodone           ###   ########.fr       */
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

void	direction_move(t_mlx *mlx, double *delx, double *dely, double frame)
{
	if (mlx->keys[W] == 1)
		m_forward(mlx, delx, dely, frame);
	if (mlx->keys[A] == 1)
		m_left(mlx, delx, dely, frame);
	if (mlx->keys[S] == 1)
		m_back(mlx, delx, dely, frame);
	if (mlx->keys[D] == 1)
		m_right(mlx, delx, dely, frame);
}
