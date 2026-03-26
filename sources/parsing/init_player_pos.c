/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player_pos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 11:55:06 by jodone            #+#    #+#             */
/*   Updated: 2026/03/26 10:55:46 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef BONUS
# include "cub3d_bonus.h"
#else
# include "cub3d.h"
#endif

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
		mlx->pos_x = col + 0.5;
		mlx->pos_y = line + 0.5;
		mlx->dir_x = 1;
		mlx->dir_y = 0;
		mlx->plane_x = 0;
		mlx->plane_y = M_PI / 4;
	}
	else if (c == 'W')
	{
		mlx->pos_x = col + 0.5;
		mlx->pos_y = line + 0.5;
		mlx->dir_x = -1;
		mlx->dir_y = 0;
		mlx->plane_x = 0;
		mlx->plane_y = -(M_PI / 4);
	}
}

static	void	set_vertical_direction(char c, t_mlx *mlx, int line, int col)
{
	if (c == 'N')
	{
		mlx->pos_x = col + 0.5;
		mlx->pos_y = line + 0.5;
		mlx->dir_x = 0;
		mlx->dir_y = -1;
		mlx->plane_x = M_PI / 4;
		mlx->plane_y = 0;
	}
	else if (c == 'S')
	{
		mlx->pos_x = col + 0.5;
		mlx->pos_y = line + 0.5;
		mlx->dir_x = 0;
		mlx->dir_y = 1;
		mlx->plane_x = -(M_PI / 4);
		mlx->plane_y = 0;
	}
}

int	set_player_start(t_mlx *mlx, t_map *map)
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
				map->map[y][x] = '0';
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}
