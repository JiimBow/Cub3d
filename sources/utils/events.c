/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarnier <mgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 15:06:03 by mgarnier          #+#    #+#             */
/*   Updated: 2026/03/19 17:23:14 by mgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key_down(int key, void *param)
{
	t_mlx		*mlx;

	mlx = (t_mlx *)param;
	mlx->keys[key] = 1;
	if (key == ESC)
		mlx_loop_end(mlx->cont);
	if (key == UP_KEY)
	{
		mlx->sp_move += 1.0;
		if (mlx->sp_move > 8.0)
			mlx->sp_move = 8.0;
	}
	if (key == DOWN_KEY)
	{
		mlx->sp_move -= 1.0;
		if (mlx->sp_move < 1.0)
			mlx->sp_move = 1.0;
	}
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
