/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 14:54:48 by jodone            #+#    #+#             */
/*   Updated: 2026/03/27 12:07:54 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	player_move(t_mlx *mlx, double delx, double dely, double frame_time)
{
	int		player_x;
	int		player_y;

	direction_move(mlx, &delx, &dely, frame_time);
	if (delx > 0)
		player_x = (mlx->pos_x + delx + 0.2);
	else
		player_x = (mlx->pos_x + delx - 0.2);
	if (mlx->s_map->map[(int)mlx->pos_y][player_x] != '1' && delx != 0.0)
	{
		open_door(mlx, player_x, mlx->pos_y);
		mlx->pos_x += delx;
		close_door(mlx, player_x, mlx->pos_y);
	}
	if (dely > 0)
		player_y = (mlx->pos_y + dely + 0.2);
	else
		player_y = (mlx->pos_y + dely - 0.2);
	if (mlx->s_map->map[player_y][(int)mlx->pos_x] != '1' && dely != 0.0)
	{
		open_door(mlx, mlx->pos_x, player_y);
		mlx->pos_y += dely;
		close_door(mlx, mlx->pos_x, player_y);
	}
	return (0);
}
