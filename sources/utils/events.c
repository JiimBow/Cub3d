/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarnier <mgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 15:06:03 by mgarnier          #+#    #+#             */
/*   Updated: 2026/03/16 16:00:46 by mgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key_down(int key, void *param)
{
	t_mlx		*mlx;

	mlx = (t_mlx *)param;
	mlx->keys[key] = 1;
	if (key == 41)
		mlx_loop_end(mlx->cont);
	player_move(mlx, key, 0, 0);
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
