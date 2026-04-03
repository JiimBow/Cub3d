/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_mlx_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarnier <mgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 12:56:09 by jodone            #+#    #+#             */
/*   Updated: 2026/04/03 09:30:14 by mgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	set_mlx_struct(t_mlx *mlx)
{
	mlx->info.height = SCREEN_H;
	mlx->info.width = SCREEN_W;
	mlx->info.title = "cub3D";
	mlx->fps_timer = 1.0;
	mlx->sp_move = 2.0;
	mlx->sp_rot = 3.0;
	mlx->zoom = 4;
	mlx->life = 6;
	mlx->hit = 0;
	mlx->anim_time = 0.0;
}
