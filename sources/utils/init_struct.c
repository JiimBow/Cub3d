/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarnier <mgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 15:15:34 by mgarnier          #+#    #+#             */
/*   Updated: 2026/03/17 10:22:40 by mgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_mlx_struct(t_mlx *mlx)
{
	ft_bzero(mlx, sizeof(*mlx));
	ft_bzero(&mlx->info, sizeof(mlx->info));
	ft_bzero(mlx->keys, 512);
	mlx->info.height = 963;
	mlx->info.width = 1920;
	mlx->info.title = "cub3D";
	mlx->frame_count = 0;
	mlx->fps_timer = 1.0;
	mlx->time = 0;
	mlx->old_time = 0;
	gettimeofday(&mlx->last_time, NULL);
	mlx->cont = mlx_init();
	mlx->win = mlx_new_window(mlx->cont, &mlx->info);
	mlx_set_fps_goal(mlx->cont, 90);
	
	//NORD
	mlx->pos_x =    4.5; mlx->pos_y = 8.5;
	mlx->dir_x =      0; mlx->dir_y =  -1;
	mlx->plane_x = 0.66; mlx->plane_y = 0;

	// //SUD
	// mlx->pos_x =     4.5; mlx->pos_y = 1.5;
	// mlx->dir_x =       0; mlx->dir_y =   1;
	// mlx->plane_x = -0.66; mlx->plane_y = 0;

	// //EST
	// mlx->pos_x = 1.5; mlx->pos_y =    4.5;
	// mlx->dir_x =   1; mlx->dir_y =      0;
	// mlx->plane_x = 0; mlx->plane_y = 0.66;
	
	// //OUEST
	// mlx->pos_x = 8.5; mlx->pos_y =     4.5;
	// mlx->dir_x =  -1; mlx->dir_y =       0;
	// mlx->plane_x = 0; mlx->plane_y = -0.66;
}
