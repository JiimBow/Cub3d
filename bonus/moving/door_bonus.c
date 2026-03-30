/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 11:05:21 by jodone            #+#    #+#             */
/*   Updated: 2026/03/30 13:11:41 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	init_door_count(t_map *map)
{
	int	x;
	int	y;
	int	count;

	y = 0;
	count = 0;
	while (map->map && map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			if (map->map[y][x] == 'D')
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

void	init_door_pos(t_map *map, t_door *door)
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
				door[i].pos_x = x;
				door[i].pos_y = y;
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
	double	diff_dist;
	int		i;

	i = 0;
	while (i < mlx->door_count)
	{
		diff_x = fabs(player_x - ((double)mlx->s_door[i].pos_x + 0.5));
		diff_y = fabs(player_y - ((double)mlx->s_door[i].pos_y + 0.5));
		diff_dist = diff_x * diff_x + diff_y * diff_y;
		if (mlx->s_map->map[mlx->s_door[i].pos_y][mlx->s_door[i].pos_x] == 'D'
			&& diff_dist < 1.3)
			mlx->s_map->map[mlx->s_door[i].pos_y][mlx->s_door[i].pos_x] = 'O';
		else if ((mlx->s_map->map[mlx->s_door[i].pos_y][mlx->s_door[i].pos_x]
			== 'O' && diff_dist > 1.5 * 1.5))
			mlx->s_map->map[mlx->s_door[i].pos_y][mlx->s_door[i].pos_x] = 'D';
		i++;
	}
}
