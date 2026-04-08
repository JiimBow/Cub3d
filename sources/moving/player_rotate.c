/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarnier <mgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 22:03:15 by mgarnier          #+#    #+#             */
/*   Updated: 2026/04/08 18:55:16 by mgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef BONUS
# include "cub3d_bonus.h"
#else
# include "cub3d.h"
#endif

void	player_rotate(t_mlx *mlx, double frame_time, double speed)
{
	double	old_dir_x;
	double	old_plane_x;

	if (frame_time < 0)
		frame_time = 0;
	old_dir_x = mlx->dir_x;
	old_plane_x = mlx->plane_x;
	if (mlx->keys[RIGHT_KEY] == 1 || mlx->keys[LEFT_KEY] == 1)
	{
		if (mlx->keys[LEFT_KEY] == 1)
			speed *= -1;
		mlx->dir_x = mlx->dir_x * cos(speed) - mlx->dir_y * sin(speed);
		mlx->dir_y = old_dir_x * sin(speed) + mlx->dir_y * cos(speed);
		mlx->plane_x = mlx->plane_x * cos(speed) - mlx->plane_y * sin(speed);
		mlx->plane_y = old_plane_x * sin(speed) + mlx->plane_y * cos(speed);
	}
}
