/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 15:06:03 by mgarnier          #+#    #+#             */
/*   Updated: 2026/03/26 10:33:18 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef BONUS
	#include "cub3d_bonus.h"
#else
	#include "cub3d.h"
#endif

void	toggle_mouse(t_mlx *mlx)
{
	if (mlx->keys[M])
	{
		if (mlx->lock_mouse == 0)
		{
			mlx_mouse_show(mlx->cont);
			mlx->lock_mouse = 1;
		}
		else
		{
			mlx_mouse_hide(mlx->cont);
			mlx->lock_mouse = 0;
		}
	}
}

void	key_down(int key, void *param)
{
	t_mlx		*mlx;

	mlx = (t_mlx *)param;
	mlx->keys[key] = 1;
	if (key == ESC)
		mlx_loop_end(mlx->cont);
	if (key == UP_KEY)
		mlx->sp_move *= 1.5;
	if (key == DOWN_KEY)
		mlx->sp_move /= 1.5;
	if (mlx->sp_move < 1.0 || mlx->sp_move > 30.0)
		mlx->sp_move = (mlx->sp_move < 1.0) * 1.0
			+ (mlx->sp_move > 30.0) * 30.0;
	if (key == E)
		mlx->zoom += 1;
	if (key == R)
		mlx->zoom -= 1;
	if (mlx->zoom < 2 || mlx->zoom > 12)
		mlx->zoom = (mlx->zoom < 2) * 2 + (mlx->zoom > 12) * 12;
	toggle_mouse(mlx);
}

void	key_up(int key, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	mlx->keys[key] = 0;
}

void	window_hook(int event, void *par)
{
	if (event == 0)
		mlx_loop_end((mlx_context)par);
}
