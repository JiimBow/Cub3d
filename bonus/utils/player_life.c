/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_life.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarnier <mgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 12:07:48 by mgarnier          #+#    #+#             */
/*   Updated: 2026/04/03 12:13:50 by mgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	hitting(void *param)
{
	t_mlx	*mlx;

	mlx = param;
	if (mlx->s_map->map[(int)mlx->pos_y][(int)mlx->pos_x] == '2'
		&& mlx->hit == 0)
	{
		mlx->hit = 1;
		mlx->life--;
	}
	if (mlx->s_map->map[(int)mlx->pos_y][(int)mlx->pos_x] == '0'
		&& mlx->hit == 1)
		mlx->hit = 0;
}

void	check_player_life(t_mlx *mlx)
{
	if (mlx->life > 5)
		mlx_put_transformed_image_to_window(mlx->cont, mlx->win,
			mlx->heart, SCREEN_W - 150, 0, 0.5, 0.5, 0);
	if (mlx->life == 5)
		mlx_put_transformed_image_to_window(mlx->cont, mlx->win,
			mlx->heart_broken, SCREEN_W - 150, 0, 0.5, 0.5, 0);
	if (mlx->life > 3)
		mlx_put_transformed_image_to_window(mlx->cont, mlx->win,
			mlx->heart, SCREEN_W - 300, 0, 0.5, 0.5, 0);
	if (mlx->life == 3)
		mlx_put_transformed_image_to_window(mlx->cont, mlx->win,
			mlx->heart_broken, SCREEN_W - 300, 0, 0.5, 0.5, 0);
	if (mlx->life > 1)
		mlx_put_transformed_image_to_window(mlx->cont, mlx->win,
			mlx->heart, SCREEN_W - 450, 0, 0.5, 0.5, 0);
	if (mlx->life == 1)
		mlx_put_transformed_image_to_window(mlx->cont, mlx->win,
			mlx->heart_broken, SCREEN_W - 450, 0, 0.5, 0.5, 0);
}
