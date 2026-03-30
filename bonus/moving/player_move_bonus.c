/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 14:54:48 by jodone            #+#    #+#             */
/*   Updated: 2026/03/30 12:58:12 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	player_move(t_mlx *mlx, double delx, double dely, double frame_time)
{
	double	player_x;
	double	player_y;

	direction_move(mlx, &delx, &dely, frame_time);
	if (delx > 0)
		player_x = (mlx->pos_x + delx + 0.2);
	else
		player_x = (mlx->pos_x + delx - 0.2);
	if (mlx->s_map->map[(int)floor(mlx->pos_y)][(int)floor(player_x)] != '1'
		&& delx != 0.0)
	{
		open_door(mlx, player_x, mlx->pos_y);
		mlx->pos_x += delx;
	}
	if (dely > 0)
		player_y = (mlx->pos_y + dely + 0.2);
	else
		player_y = (mlx->pos_y + dely - 0.2);
	if (mlx->s_map->map[(int)floor(player_y)][(int)floor(mlx->pos_x)] != '1'
		&& dely != 0.0)
	{
		open_door(mlx, mlx->pos_x, player_y);
		mlx->pos_y += dely;
	}
	return (0);
}
