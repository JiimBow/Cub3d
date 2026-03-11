/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarnier <mgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 15:15:34 by mgarnier          #+#    #+#             */
/*   Updated: 2026/03/11 15:29:05 by mgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_mlx_struct(t_mlx *mlx)
{
	ft_bzero(mlx, sizeof(*mlx));
	ft_bzero(&mlx->info, sizeof(mlx->info));
	mlx->info.height = 963;
	mlx->info.width = 1920;
	mlx->info.title = "cub3D";
	mlx->frame_count = 0;
	mlx->fps_timer = 1.0;
	gettimeofday(&mlx->last_time, NULL);
	mlx->context = mlx_init();
	mlx->window = mlx_new_window(mlx->context, &mlx->info);
	mlx_set_fps_goal(mlx->context, 90);
}
