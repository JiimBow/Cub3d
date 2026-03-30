/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 11:05:21 by jodone            #+#    #+#             */
/*   Updated: 2026/03/30 15:15:03 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	open_door(t_mlx *mlx, double player_x, double player_y)
{
	double	diff_x;
	double	diff_y;
	double	diff_dist;
	int		i;

	i = 0;
	while (i < mlx->door_count)
	{
		diff_x = fabs(player_x - ((double)mlx->s_door[i].pos_x + 0.5));
		diff_y = fabs(player_y - ((double)mlx->s_door[i].pos_y + 0.5));
		diff_dist = diff_x * diff_x + diff_y * diff_y;
		if (mlx->s_map->map[mlx->s_door[i].pos_y][mlx->s_door[i].pos_x] == 'D'
			&& diff_dist < 1.3 * 1.3)
			mlx->s_map->map[mlx->s_door[i].pos_y][mlx->s_door[i].pos_x] = 'O';
		else if ((mlx->s_map->map[mlx->s_door[i].pos_y][mlx->s_door[i].pos_x]
			== 'O' && diff_dist > 1.5 * 1.5))
			mlx->s_map->map[mlx->s_door[i].pos_y][mlx->s_door[i].pos_x] = 'D';
		i++;
	}
}
