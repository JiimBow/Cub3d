/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player_pos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 11:55:06 by jodone            #+#    #+#             */
/*   Updated: 2026/03/24 16:31:41 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_start_char(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

static	void	set_horizontal_direction(char c, t_mlx *mlx, int line, int col)
{
	if (c == 'E')
	{
		mlx->pos_x = col - 0.5;
		mlx->pos_y = line + 0.5;
		mlx->dir_x = 1;
		mlx->dir_y = 0;
	}
	else if (c == 'W')
	{
		mlx->pos_x = col - 0.5;
		mlx->pos_y = line + 0.5;
		mlx->dir_x = -1;
		mlx->dir_y = 0;
	}
}

static	void	set_vertical_direction(char c, t_mlx *mlx, int line, int col)
{
	if (c == 'N')
	{
		mlx->pos_x = col - 0.5;
		mlx->pos_y = line + 0.5;
		mlx->dir_x = 0;
		mlx->dir_y = -1;
	}
	else if (c == 'S')
	{
		mlx->pos_x = col - 0.5;
		mlx->pos_y = line + 0.5;
		mlx->dir_x = 0;
		mlx->dir_y = 1;
	}
}

void	set_player_start(t_mlx *mlx, t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			if (is_start_char(map->map[y][x]))
			{
				set_vertical_direction(map->map[y][x], mlx, y, x);
				set_horizontal_direction(map->map[y][x], mlx, y, x);
				return ;
			}
			x++;
		}
		y++;
	}
}
