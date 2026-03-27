/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimbow <jimbow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 11:05:21 by jodone            #+#    #+#             */
/*   Updated: 2026/03/27 17:21:53 by jimbow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	init_door_pos(t_mlx *mlx, t_map *map, t_door *door, int type)
{
	int	x;
	int	y;
	int	i;

	y = 0;
	i = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			if (map->map[y][x] == 'D')
			{
				if (type == 0)
					mlx->door_count++;
				else
				{
					door[i].pos_x = x;
					door[i].pos_y = y;
				}
				i++;
			}
			x++;
		}
		y++;
	}
}

void	open_door(t_mlx *mlx, double player_x, double player_y)
{
	double	diff_x;
	double	diff_y;
	// double	diff_dist;
	int		i;

	i = 0;
	while (i < mlx->door_count)
	{
		diff_x = fabs(player_x - (mlx->s_door[i].pos_x + 0.5));
		diff_y = fabs(player_y - (mlx->s_door[i].pos_y + 0.5));
		// diff_dist = diff_x * diff_x + diff_y * diff_y;
		printf("%f    %f    %f    %f\n", diff_x, diff_y, mlx->pos_x, mlx->pos_y);
		if (mlx->s_map->map[mlx->s_door[i].pos_y][mlx->s_door[i].pos_x] == 'D'
			&& diff_x <= 0.8 && diff_y <= 0.8)
			mlx->s_map->map[mlx->s_door[i].pos_y][mlx->s_door[i].pos_x] = 'O';
		else if ((mlx->s_map->map[mlx->s_door[i].pos_y][mlx->s_door[i].pos_x]
			== 'O' && (diff_x > 1.2 || diff_y > 1.2)))
			mlx->s_map->map[mlx->s_door[i].pos_y][mlx->s_door[i].pos_x] = 'D';
		i++;
	}
}
